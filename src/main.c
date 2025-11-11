/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:55:37 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/11 14:39:49 by mbatty           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_ctx	ctx;

	if (!ctx_init(&ctx, ac, av))
	{
		ctx_delete(&ctx);
		return (1);
	}
	ctx_delete(&ctx);
	return (0);
}
