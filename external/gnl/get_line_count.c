/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:17:02 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/11 10:21:50 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

int		get_line_count(const char *path)
{
	int		fd;
	int		res;
	int		read_bytes;
	char	buf;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	read_bytes = 1;
	res = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, &buf, 1);
		if (buf == '\n')
			res++;
		buf = '\0';
	}
	close(fd);
	if (read_bytes < 0)
		return (-1);
	return (res);
}
