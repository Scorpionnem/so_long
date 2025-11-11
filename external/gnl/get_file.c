/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:21:59 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/11 10:35:54 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

static void	free_get_file(char **res, int fd)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	close(fd);
}

static int	fill_file(char **res, int fd)
{
	char	*line;
	int		alloc_error;
	int		i;

	i = 0;
	line = get_next_line(fd, &alloc_error);
	if (alloc_error)
	{
		free_get_file(res, fd);
		return (0);
	}
	res[i++] = line;
	while (line)
	{
		line = get_next_line(fd, &alloc_error);
		if (alloc_error)
		{
			free_get_file(res, fd);
			return (0);
		}
		res[i++] = line;
	}
	return (1);
}

static void	remove_nl(char *str)
{
	if (str[ft_strlengnl(str) - 1] == '\n')
		str[ft_strlengnl(str) - 1] = '\0';
}

char	**get_file(const char *path)
{
	char	**res;
	int		fd;
	int		i;

	i = 0;
	res = ft_callocgnl((get_line_count(path) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(res);
		return (NULL);
	}
	if (!fill_file(res, fd))
		return (NULL);
	while (res[i])
		remove_nl(res[i++]);
	close(fd);
	return (res);
}
