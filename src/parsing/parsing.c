/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:50:17 by mbatty            #+#    #+#             */
/*   Updated: 2025/12/02 23:02:48 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

char	*append_char(char *str, char c)
{
	char	*res;

	if (!str)
	{
		res = ft_calloc(2, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = c;
		return (res);
	}
	res = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	if (!res)
	{
		free(str);
		return (0);
	}
	ft_memcpy(res, str, ft_strlen(str));
	res[ft_strlen(str)] = c;
	free(str);
	return (res);
}

/*
	key char args
	
	wall ? texture
	floor ? texture
	collectible ? texture
	exit ? texture
	player ? texture
	enemy ? texture health attack
*/

int	find_define(t_ctx *ctx, char **line)
{
	char	*key;
	char	*first_val;

	key = line[0];
	if (!key)
		return (1);
	first_val = line[1];
	if (!ft_strncmp(line[0], "wall", sizeof("wall")) && first_val)
		ctx->map_infos.walls = append_char(ctx->map_infos.walls, first_val[0]);
	else if (!ft_strncmp(line[0], "floor", sizeof("floor")) && first_val)
		ctx->map_infos.floors = append_char(ctx->map_infos.floors, first_val[0]);
	else if (!ft_strncmp(line[0], "collectible", sizeof("collectible")) && first_val)
		ctx->map_infos.collectibles = append_char(ctx->map_infos.collectibles, first_val[0]);
	else if (!ft_strncmp(line[0], "enemy", sizeof("enemy")) && first_val)
		ctx->map_infos.enemies = append_char(ctx->map_infos.enemies, first_val[0]);
	else if (!ft_strncmp(line[0], "exit", sizeof("exit")) && first_val)
		ctx->map_infos.exit = first_val[0];
	else if (!ft_strncmp(line[0], "player", sizeof("player")) && first_val)
		ctx->map_infos.player = first_val[0];
	else
		return (0);
	return (1);
}

int	is_fully_defined(t_ctx *ctx)
{
	if (ctx->map_infos.collectibles == NULL)
		return (0);
	if (ctx->map_infos.enemies == NULL)
		return (0);
	if (ctx->map_infos.floors == NULL)
		return (0);
	if (ctx->map_infos.walls == NULL)
		return (0);
	if (ctx->map_infos.player == '\0')
		return (0);
	if (ctx->map_infos.exit == '\0')
		return (0);
	return (1);
}

int	parse_defines(t_ctx *ctx)
{
	int		i;
	char	**line;

	i = 0;
	while (ctx->file[i])
	{
		line = ft_split(ctx->file[i], ' ');
		if (!line)
			return (0);
		if (!find_define(ctx, line))
		{
			free_2d(line);
			break ;
		}
		free_2d(line);
		i++;
	}
	if (!is_fully_defined(ctx))
	{
		ft_putendl_fd("so_long: not all informations are defined in given map file", 2);
		return (0);
	}
	ctx->map = &ctx->file[i];
	ctx->map_infos.width = ft_strlen(ctx->map[0]);
	i = 0;
	while (ctx->map[i])
		i++;
	ctx->map_infos.height = i;
	return (1);
}

void	print_map_infos(t_ctx *ctx)
{
	printf("PLAYER: %c\n", ctx->map_infos.player);
	printf("EXIT: %c\n", ctx->map_infos.exit);
	printf("WALLS: %s\n", ctx->map_infos.walls);
	printf("ENEMIES: %s\n", ctx->map_infos.enemies);
	printf("COLLECTIBLES: %s\n\n", ctx->map_infos.collectibles);
	int	i = 0;
	while (ctx->map[i])
		printf("%s\n", ctx->map[i++]);
}

int	parse_file(t_ctx *ctx)
{
	if (!parse_defines(ctx))
		return (0);
	if (!parse_map(ctx))
		return (0);
	print_map_infos(ctx);
	return (1);
}
