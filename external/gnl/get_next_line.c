/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mbatty <mewen.mewen@hotmail.com>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/17 10:08:20 by mbatty			#+#	#+#			 */
/*   Updated: 2025/02/15 12:59:05 by mbatty		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_internal.h"

int	size_to_nl(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*split_line(char *buffer, int *allocerror)
{
	char	*line;
	int		i;

	i = 0;
	if (ft_strlengnl(buffer) == 0)
		return (NULL);
	line = ft_callocgnl((size_to_nl(buffer) + 2), sizeof(char));
	if (!line)
		return (alloc_error(allocerror));
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (line);
}

static char	*split_buffer(char *buffer, int len, int *allocerror)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || ft_strchrgnl(buffer, '\n') == 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_callocgnl((ft_strlengnl(&buffer[len]) + 2), sizeof(char));
	if (!line)
		return (alloc_error(allocerror));
	while (buffer[len + i])
	{
		line[i] = buffer[len + i];
		i++;
	}
	free(buffer);
	return (line);
}

static char	*read_filegnl(int fd, char *buffer, int i, int *allocerror)
{
	char	*str;

	if (!buffer)
		buffer = ft_callocgnl(1, 1);
	if (!buffer)
		return (alloc_error(allocerror));
	while (i > 0 && !ft_strchrgnl(buffer, '\n') && buffer)
	{
		str = ft_callocgnl((BUFFER_SIZE + 2), sizeof(char));
		if (!str)
			return (alloc_error(allocerror));
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer = ft_joinfreegnl(buffer, str);
		if (!buffer)
			alloc_error(allocerror);
		free(str);
	}
	return (buffer);
}

char	*get_next_line(int fd, int *allocerror)
{
	static char	*buffer;
	char		*line;

	(*allocerror) = 0;
	if (!allocerror || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_filegnl(fd, buffer, 1, allocerror);
	if (buffer == NULL)
		return (NULL);
	line = split_line(buffer, allocerror);
	buffer = split_buffer(buffer, ft_strlengnl(line), allocerror);
	return (line);
}
