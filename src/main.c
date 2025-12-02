/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:55:37 by mbatty            #+#    #+#             */
/*   Updated: 2025/12/02 23:58:03 by mbatty           ###   ########.fr       */
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
	ctx->player_x = 1.5;
	ctx->player_y = 1.5;
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

int	key_hook(int keycode, t_ctx *ctx)
{
	if (keycode == ESC_KEY)
		close_window(ctx);
	if (keycode == 97) // A
		ctx->left_input = true;
	if (keycode == 100) // D
		ctx->right_input = true;
	if (keycode == 119) // W
		ctx->up_input = true;
	if (keycode == 115) // S
		ctx->down_input = true;
	return (1);
}

int	key_hook_release(int keycode, t_ctx *ctx)
{
	if (keycode == 97) // A
		ctx->left_input = false;
	if (keycode == 100) // D
		ctx->right_input = false;
	if (keycode == 119) // W
		ctx->up_input = false;
	if (keycode == 115) // S
		ctx->down_input = false;
	return (1);
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	put_pixel(t_ctx *ctx, int x, int y, int color)
{
	if (x < 0 || x >= ctx->img.width || y < 0 || y >= ctx->img.height)
		return ;

	char	*dst;

	dst = ctx->img.addr + (y * ctx->img.line_length + x * (ctx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_image(t_ctx *ctx, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->img.height)
	{
		x = 0;
		while (x < ctx->img.width)
		{
			put_pixel(ctx, x, y, color);
			x++;
		}
		y++;
	}
}

int	put_square(t_ctx *ctx, int x, int y, int size, int color)
{
	int	xx;
	int	yy;

	xx = 0;
	while (xx < size)
	{
		yy = 0;
		while (yy < size)
		{
			put_pixel(ctx, xx + x, yy + y, color);
			yy++;
		}
		xx++;
	}
	return (1);
}

# define CAMERA_SIZE_X 5
# define CAMERA_SIZE_Y 4

int	render_map(t_ctx *ctx)
{
	int	x;
	int	y;

	int	cam_x;
	int	cam_y;

	cam_x = floor(ctx->player_x);
	cam_y = floor(ctx->player_y);
	int x_min = cam_x - CAMERA_SIZE_X;
	int y_min = cam_y - CAMERA_SIZE_Y;
	int x_max = cam_x + CAMERA_SIZE_X;
	int y_max = cam_y + CAMERA_SIZE_Y;

	y = y_min;
	while (y <= y_max + 1)
	{
		x = x_min;
		while (x <= x_max + 1)
		{
				float	relative_x;
				float	relative_y;
				int		pos_x;
				int		pos_y;
					
				relative_x = (float)x - ctx->player_x;
				relative_y = (float)y - ctx->player_y;
				pos_x = (int)((relative_x + CAMERA_SIZE_X) * 64);
				pos_y = (int)((relative_y + CAMERA_SIZE_Y) * 64);

			if (x >= 0 && y >= 0 && x < ctx->map_infos.width && y < ctx->map_infos.height)
			{
				if (ft_strchr(ctx->map_infos.walls, ctx->map[y][x])) // WALLS
					put_square(ctx, pos_x, pos_y, 64, 0x000000FF);
				if (ft_strchr(ctx->map_infos.floors, ctx->map[y][x])) // WALLS
					put_square(ctx, pos_x, pos_y, 64, 0x00000055);
			}
			x++;
		}
		y++;
	}
	return (1);
}

bool	is_in_bounds(t_ctx *ctx, float x, float y)
{
	return (x >= 0 && y >= 0 && x < ctx->map_infos.width && y < ctx->map_infos.height);
}

int	update(t_ctx *ctx)
{
	if (ctx->up_input && is_in_bounds(ctx, ctx->player_x, (ctx->player_y - 0.5) - 0.01) && ctx->map[(int)((ctx->player_y - 0.5) - 0.01)][(int)ctx->player_x] != '1')
		ctx->player_y -= 0.01;
	if (ctx->down_input && is_in_bounds(ctx, ctx->player_x, (ctx->player_y + 0.5) + 0.01) && ctx->map[(int)((ctx->player_y + 0.5) + 0.01)][(int)ctx->player_x] != '1')
		ctx->player_y += 0.01;
	if (ctx->left_input && is_in_bounds(ctx, (ctx->player_x - 0.5) - 0.01, ctx->player_y) && ctx->map[(int)(ctx->player_y)][(int)((ctx->player_x - 0.5) - 0.01)] != '1')
		ctx->player_x -= 0.01;
	if (ctx->right_input && is_in_bounds(ctx, (ctx->player_x + 0.5) + 0.01, ctx->player_y) && ctx->map[(int)(ctx->player_y)][(int)((ctx->player_x + 0.5) + 0.01)] != '1')
		ctx->player_x += 0.01;
	return (1);
}

int	loop_hook(t_ctx *ctx)
{
	fill_image(ctx, 0x00000000);

	update(ctx);
	render_map(ctx);
	put_square(ctx, (ctx->window_width / 2) - 32, (ctx->window_height / 2) - 32, 64, 0x0000FFAA);
	mlx_put_image_to_window(ctx->mlx, ctx->mlx_win, ctx->img.data, 0, 0);
	return (1);
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
