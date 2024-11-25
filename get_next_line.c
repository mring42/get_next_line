/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:23:51 by mring             #+#    #+#             */
/*   Updated: 2024/11/25 12:31:21 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *buffer)
{
	int		amountread;
	int		nextread;

	while (amountread > 0)
	{
		amountread = read(fd, buffer, BUFFER_SIZE);
		if (amountread < 0)
		{
			buffer[0] = '\0';
			return (NULL);
		}

			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char *line;
	char *nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(line, buf, BUFFER_SIZE);
	// line = readline(fd, buf);

	
	return (line);

}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("testfile.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line);
	}
	close(fd);
}
/*

FORBIDDEN:
libft, lseek(), global variables (outside of functions)

what does gnl do?
gnl takes a file descriptor (fd) as input, and reads from it.
every line should end with \n unless its end of file.

a single buffer static variable
allowed to read, malloc and free.







logic read from my old gnl.
gnl():
define variables necessary
static char buffer[open_max][buffer_size + 1] < our single static for bonus
then check fd and buffer size
create a new allocated string (char *) with ft_strdup.
check if it failed
loop over the line and check for \n && that reading has not failed
read and write into a variable, check if it failed,
if it did, free, set null and return
join the read amount into a string to combine them,
check if line is empty or 0 and free if it is and return null.
loop end
ft_strchr the line for a \n, and save it to a variable
add the logic the remove the read part from the buffer (errcheck?)

used function in utils: strjoin, strlcpy, strdup, strchr and strlen
err_check for the logic of the remaining buffer to copy
and to handle empty/null buffers

*/