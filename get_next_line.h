/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:54 by mring             #+#    #+#             */
/*   Updated: 2024/11/25 17:21:16 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
// # include <limits.h>

# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, size_t dstlen);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *str1, char const *str2, int amountread);
// char	*readline(int fd, char *buffer, char *line);
char	*get_next_line(int fd);
int		err_check(char *next_line, char *line, char *buf);

#endif