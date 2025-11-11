/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:44:29 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/11 14:44:42 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

static int	is_all_walls(char *walls_set, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(walls_set, line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	are_edges_walls(char *walls_set, char *line)
{
	if (!ft_strchr(walls_set, line[0]))
		return (0);
	if (!ft_strchr(walls_set, line[ft_strlen(line) - 1]))
		return (0);
	return (1);
}

static int	is_map_closed(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (!is_all_walls(ctx->map_infos.walls, ctx->map[i]))
		return (0);
	while (ctx->map[i])
	{
		if (!are_edges_walls(ctx->map_infos.walls, ctx->map[i]))
			return (0);
		i++;
	}
	if (!is_all_walls(ctx->map_infos.walls, ctx->map[i - 1]))
		return (0);
	return (1);
}

static int	is_map_rectangular(t_ctx *ctx)
{
	int 	i;
	size_t	first_len;

	i = 0;
	first_len = ft_strlen(ctx->map[0]);
	while (ctx->map[i])
	{
		if (ft_strlen(ctx->map[i]) != first_len)
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(t_ctx *ctx)
{
	if (!is_map_rectangular(ctx))
	{
		ft_putendl_fd("so_long: map is not in a correct format", 2);
		return (0);
	}
	if (!is_map_closed(ctx))
	{
		ft_putendl_fd("so_long: map is not closed", 2);
		return (0);
	}
	return (1);
}
