/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsakai <jinsakai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:41:21 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/27 15:26:16 by jinsakai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*getbuff(int fd, char *buff)
{
	char	*tmp;
	ssize_t	nbytes;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && (!buff || !ft_strchr(buff, '\n')))
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		tmp[nbytes] = 0;
		buff = ft_strjoin(buff, tmp);
	}
	if (nbytes == -1)
		return (free(buff), free(tmp), NULL);
	free(tmp);
	return (buff);
}

char	*ext_line(char *buff)
{
	int		i;
	char	*line;

	if (!*buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(i + 1 + (buff[i] == '\n'));
	if (!line)
		return (NULL);
	ft_strncpy(line, buff, i + (buff[i] == '\n'));
	return (line);
}

char	*updatebuff(char *buff)
{
	int		i;
	char	*nbuff;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	nbuff = malloc(ft_strlen(buff) - i + 1);
	if (!nbuff)
		return (NULL);
	i++;
	ft_strncpy(nbuff, buff + i, ft_strlen(buff + i));
	free(buff);
	return (nbuff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = getbuff(fd, buff);
	if (!buff)
		return (NULL);
	line = ext_line(buff);
	buff = updatebuff(buff);
	return (line);
}

// int main(void)
// {
// 	int fd = open("dirtst", O_RDONLY);
// 	// int ffd = open("ff", O_RDWR);

// 	if (fd == -1)
// 		printf("failed\n");

// 	char *line = get_next_line(fd);
// 	printf("gg 1: %s", line);
// 	free(line);

// 	// char *ffline = get_next_line(ffd);
// 	// printf("ff 1:%s", ffline);
// 	// free(ffline);

// 	// line = get_next_line(fd);
// 	// printf("gg 2: %s", line);
// 	// free(line);

// 	// ffline = get_next_line(ffd);
// 	// printf("ff 2:%s", ffline);
// 	// free(ffline);

// 	close(fd);
// 	// close(ffd);
// 	return 0;
// }