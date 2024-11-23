/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 23:41:21 by rahmoham          #+#    #+#             */
/*   Updated: 2024-11-21 23:41:21 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*getbuff(int fd, char *buff)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*tbuff;
	ssize_t	nbytes;

	nbytes = read(fd, tmp, BUFFER_SIZE);
	while (nbytes > 0)
	{
		tmp[nbytes] = 0;
		tbuff = ft_strjoin(buff, tmp);
		free(buff);
		buff = tbuff;
		if (!buff)
		{
			free(buff);
			return (NULL);
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (nbytes < 0 || (nbytes == 0 && !buff))
		return (free(buff), NULL);
	return (buff);
}

char	*ext_line(char *buff)
{
	int		i;
	char	*line;

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
	char	*nbuff;
	char	*nl_pos;

	nl_pos = ft_strchr(buff, '\n');
	if (!nl_pos)
	{
		free(buff);
		return (NULL);
	}
	nbuff = ft_strdup(nl_pos + 1);
	if (!nbuff)
	{
		free(buff);
		return (NULL);
	}
	free(buff);
	return (nbuff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	buff = getbuff(fd, buff);
	if (!buff)
		return (NULL);
	line = ext_line(buff);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	buff = updatebuff(buff);
	return (line);
}

int main(void)
{
	int fd = open("gg", O_RDWR , 0777);

	char *line = get_next_line(fd);

	printf("first :%s", line);

	free(line);
	close(fd);
	return 0;
}