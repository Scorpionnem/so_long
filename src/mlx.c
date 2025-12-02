/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:13:02 by mbatty            #+#    #+#             */
/*   Updated: 2025/12/02 23:21:09 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

int	close_window(t_ctx *ctx)
{
	mlx_loop_end(ctx->mlx);
	return (0);
}

void	set_hooks(t_ctx *ctx)
{
	mlx_hook(ctx->mlx_win, 17, 0, close_window, ctx);
	mlx_loop_hook(ctx->mlx, loop_hook, ctx);
	mlx_hook(ctx->mlx_win, 2, 1L << 0, key_hook, ctx); // KEY_PRESS
	mlx_hook(ctx->mlx_win, 3, 1L << 1, key_hook_release, ctx); // KEY_RELEASE
	// mlx_mouse_hook(ctx->mlx_win, mouse_hook, ctx);
	mlx_loop(ctx->mlx);
}

void	free_mlx(t_ctx *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->img.data);
	mlx_destroy_window(ctx->mlx, ctx->mlx_win);
	mlx_destroy_display(ctx->mlx);
	free(ctx->mlx);
}

int	init_mlx(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
	if (!ctx->mlx)
		return (0);
	ctx->mlx_win = mlx_new_window(ctx->mlx,
			ctx->window_width, ctx->window_height, "so_long");
	if (!ctx->mlx_win)
		return (0);
	ctx->img.width = ctx->window_width;
	ctx->img.height = ctx->window_height;
	ctx->img.data = mlx_new_image(ctx->mlx, ctx->window_width, ctx->window_height);
	if (!ctx->img.data)
		return (0);
	ctx->img.addr = mlx_get_data_addr(ctx->img.data, &ctx->img.bits_per_pixel,
			&ctx->img.line_length, &ctx->img.endian);
	ctx->img.width = ctx->window_width;
	ctx->img.height = ctx->window_height;
	set_hooks(ctx);
	return (1);
}
