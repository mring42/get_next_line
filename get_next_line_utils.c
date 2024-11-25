/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:56 by mring             #+#    #+#             */
/*   Updated: 2024/11/25 17:16:20 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstlen - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, len);
	return (dst);
}

char	*ft_strjoin(char *str1, char const *str2, int amountread)
{
	char	*newstr;
	size_t	str1_len;
	size_t	str2_len;

	if (!str1 || !str2)
		return (NULL);
	str1_len = ft_strlen(str1);
	str2_len = amountread;
	newstr = malloc(str1_len + str2_len + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, str1, str1_len + 1);
	ft_strlcpy((newstr + str1_len), str2, str2_len + 1);
	free(str1);
	return (newstr);
}
