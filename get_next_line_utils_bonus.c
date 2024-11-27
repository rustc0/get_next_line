/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsakai <jinsakai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:06:43 by jinsakai          #+#    #+#             */
/*   Updated: 2024/11/27 15:12:37 by jinsakai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *buff, char *tmp)
{
	char	*str;
	size_t	buff_len;
	size_t	tmp_len;

	if (tmp == NULL)
		return (NULL);
	if (!buff)
	{
		buff = (char *)malloc(1);
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	buff_len = ft_strlen(buff);
	tmp_len = ft_strlen(tmp);
	str = malloc(buff_len + tmp_len + 1);
	if (str == NULL)
	{
		free(buff);
		return (NULL);
	}
	ft_strncpy(str, buff, buff_len);
	ft_strncpy(str + buff_len, tmp, tmp_len);
	free(buff);
	return (str);
}

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	size_t	i;

	if (!src || !dest)
		return (NULL);
	i = 0;
	while (src[i] && i < num)
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
