/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:53:01 by hurabe            #+#    #+#             */
/*   Updated: 2024/07/15 18:04:28 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		byte;
	int		i;
	char	c;
	char	*str_buffer;

	if (BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	str_buffer = (char *)malloc(10000000);
	byte = read(fd, &c, 1); // each every one charcterfrom txt file
	if (!str_buffer)
		return (NULL);
	while (byte > 0)
	{
		str_buffer[i] = c;
		i++;
		if (c == '\n' || c == EOF)
			break ;
		byte = read(fd, &c, 1);
	}
	// no more char OR error happens
	if (i == 0 || byte < 0)
	{
		free(str_buffer);
		return (NULL);
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;
	char	*path;

	path = "test.txt";
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("i: %i\n", i);
		printf("fd: %i, %s\n", fd, str);
		i++;
	}
	return (0);
}
