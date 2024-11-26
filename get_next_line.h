/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 23:42:06 by rahmoham          #+#    #+#             */
/*   Updated: 2024-11-21 23:42:06 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*updatebuff(char *buff);
char	*ext_line(char *buff);

size_t	ft_strlen(const char *str);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *buff, char *tmp);
char	*ft_strncpy(char *dest, const char *src, size_t num);

#endif