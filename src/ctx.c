/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:43:50 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 14:25:12 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

int	ctx_init(t_ctx *ctx, int ac, char **av)
{
	ft_bzero(ctx, sizeof(t_ctx));
	if (ac != 2)
	{
		ft_putendl_fd("Invalid argument count", 2);
		return (0);
	}
	ctx->file = get_file(av[1]);
	if (!ctx->file)
		return (0);
	if (!parse_file(ctx))
		return (0);
	ctx->window_width = 640;
	ctx->window_height = 512;
	ctx->player.pos.x = 1.5;
	ctx->player.pos.y = 1.5;
	update_delta(ctx);
	if (!init_mlx(ctx))
		return (0);
	return (1);
}

void	ctx_delete(t_ctx *ctx)
{
	int	i;

	i = 0;
	if (ctx->file)
		free_2d(ctx->file);
	if (ctx->map_infos.collectibles)
		free(ctx->map_infos.collectibles);
	if (ctx->map_infos.enemies)
		free(ctx->map_infos.enemies);
	if (ctx->map_infos.floors)
		free(ctx->map_infos.floors);
	if (ctx->map_infos.walls)
		free(ctx->map_infos.walls);
}
