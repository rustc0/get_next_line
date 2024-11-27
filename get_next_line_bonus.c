/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsakai <jinsakai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 06:49:59 by jinsakai          #+#    #+#             */
/*   Updated: 2024/11/27 15:15:37 by jinsakai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*getbuff(int fd, char *buff)
{
	char	*tmp;
	ssize_t	nbytes;

	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && !ft_strchr(buff, '\n'))
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
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = getbuff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ext_line(buff[fd]);
	buff[fd] = updatebuff(buff[fd]);
	return (line);
}
