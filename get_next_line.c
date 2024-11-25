/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:51 by mring             #+#    #+#             */
/*   Updated: 2024/11/25 17:38:38 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *buffer, char *line)
{
	int	amountread;

	amountread = 1;
	while (amountread > 0 && !(ft_strchr(line, '\n')))
	{
		amountread = read(fd, buffer, BUFFER_SIZE);
		if (amountread < 0)
		{
			free(line);
			buffer[0] = '\0';
			return (NULL);
		}
		line = ft_strjoin(line, buffer, amountread);
		if (ft_strlen(line) == 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	line = readline(fd, buffer, line);
	if (!line)
		return (NULL);
	nextline = ft_strchr(line, '\n');
	if (nextline != NULL)
	{
		ft_strlcpy(buffer, nextline + 1, BUFFER_SIZE + 1);
		line[nextline - line + 1] = '\0';
	}
	else
	{
		line[ft_strlen(line)] = '\0';
		buffer[0] = '\0';
	}
	return (line);
}

// int	main(void)
// {
// 	char *line;
// 	int fd;

// 	fd = open("testfile.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("$");
// 	close(fd);
// }