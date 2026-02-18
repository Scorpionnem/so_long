/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:55:37 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/18 13:08:57 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	put_pixel(t_ctx *ctx, int x, int y, int color)
{
	if (x < 0 || x >= ctx->img.width || y < 0 || y >= ctx->img.height)
		return ;

	*(unsigned int *)(ctx->img.addr + (y * ctx->img.line_length + x * (ctx->img.bits_per_pixel / 8))) = color;
}

void	clear_screen(t_ctx *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->img.height)
	{
		x = 0;
		while (x < ctx->img.width)
		{
			put_pixel(ctx, x, y, 0x00000000);
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

int	render(t_ctx *ctx)
{
	int	x;
	int	y;

	int	cam_x;
	int	cam_y;

	cam_x = floor(ctx->player.pos.x);
	cam_y = floor(ctx->player.pos.y);
	int x_min = cam_x - CAMERA_SIZE_X;
	int y_min = cam_y - CAMERA_SIZE_Y;
	int x_max = cam_x + CAMERA_SIZE_X;
	int y_max = cam_y + CAMERA_SIZE_Y;
	float	relative_x;
	float	relative_y;
	float		pos_x;
	float		pos_y;

	y = y_min;
	while (y <= y_max + 1)
	{
		x = x_min;
		while (x <= x_max + 1)
		{	
			relative_x = (float)x - ctx->player.pos.x;
			relative_y = (float)y - ctx->player.pos.y;
			pos_x = (int)((relative_x + CAMERA_SIZE_X) * TILE_SIZE);
			pos_y = (int)((relative_y + CAMERA_SIZE_Y) * TILE_SIZE);

			if (x >= 0 && y >= 0 && x < ctx->map_infos.width && y < ctx->map_infos.height)
			{
				if (ft_strchr(ctx->map_infos.walls, ctx->map[y][x])) // WALLS
					put_square(ctx, pos_x, pos_y, TILE_SIZE, 0x000000FF);
				if (ft_strchr(ctx->map_infos.floors, ctx->map[y][x])) // WALLS
					put_square(ctx, pos_x, pos_y, TILE_SIZE, 0x00000055);
			}
			x++;
		}
		y++;
	}
	relative_x = (float)3 - ctx->player.pos.x;
	relative_y = (float)3 - ctx->player.pos.y;
	pos_x = (int)((relative_x + CAMERA_SIZE_X) * TILE_SIZE);
	pos_y = (int)((relative_y + CAMERA_SIZE_Y) * TILE_SIZE);

	put_square(ctx, (ctx->window_width / 2) - PLAYER_SIZE / 2, (ctx->window_height / 2) - PLAYER_SIZE / 2, PLAYER_SIZE, 0x0000FFAA);
	return (1);
}

bool	is_in_bounds(t_ctx *ctx, float x, float y)
{
	return (x >= 0 && y >= 0 && x < ctx->map_infos.width && y < ctx->map_infos.height);
}

void	update_delta(t_ctx *ctx)
{
	double	current_frame;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	current_frame = tv.tv_sec + tv.tv_usec * 1e-6;
	ctx->delta = current_frame - ctx->last_frame;
	ctx->last_frame = current_frame;
}

#define MOVE_SPEED 3.0

void	start_shake(t_ctx *ctx, float duration, float speed, float force)
{
	ctx->shake.active = true;
	ctx->shake.timer = 0;
	ctx->shake.duration = duration;
	ctx->shake.speed = speed;
	ctx->shake.force = force;
}

void	update_shake(t_ctx *ctx)
{
	if (!ctx->shake.active)
	{
		ctx->shake.x = 0;
		ctx->shake.y = 0;
		ctx->shake.timer = 0;
		return ;
	}
	ctx->shake.timer += ctx->delta;
	if (ctx->shake.timer >= ctx->shake.duration)
		ctx->shake.active = false;
	ctx->shake.x = sin(ctx->shake.timer * ctx->shake.speed) * ctx->shake.force;
	ctx->shake.y = cos(ctx->shake.timer * ctx->shake.speed) * ctx->shake.force;
}

void	update_input(t_ctx *ctx)
{
	ctx->player.delta.x = 0;
	ctx->player.delta.y = 0;
	if (ctx->up_input)
		ctx->player.delta.y = -MOVE_SPEED;
	if (ctx->down_input)
		ctx->player.delta.y = MOVE_SPEED;
	if (ctx->left_input)
		ctx->player.delta.x = -MOVE_SPEED;
	if (ctx->right_input)
		ctx->player.delta.x = MOVE_SPEED;
}

int	update(t_ctx *ctx)
{
	update_delta(ctx);
	update_shake(ctx);
	update_input(ctx);
	entity_update(ctx, &ctx->player);
	return (1);
}

int	loop_hook(t_ctx *ctx)
{
	clear_screen(ctx);

	update(ctx);

	render(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->mlx_win, ctx->img.data, ctx->shake.x, ctx->shake.y);
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
