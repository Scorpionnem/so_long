/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:22:36 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/18 13:13:52 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

int	get_tile(t_ctx *ctx, float fx, float fy)
{
	int	x = floor(fx);
	int	y = floor(fy);
	if (x >= ctx->map_infos.width || y >= ctx->map_infos.height || x < 0 || y < 0)
		return (-1);
	return (ctx->map[y][x]);
}

#define NOT_SOLID_TILES "0CEP"

int	sign(int n)
{
	if (n >= 0)
		return (1);
	return (-1);
}

void	entity_update(t_ctx *ctx, t_entity *e)
{
	t_vec2	delta;
	delta = e->delta;

	t_vec2	new_pos;
	new_pos.x = e->pos.x + delta.x * ctx->delta;
	new_pos.y = e->pos.y + delta.y * ctx->delta;

	float	player_half_size = ((float)(PLAYER_SIZE / 2.0) / (float)TILE_SIZE);

	t_vec2	new_pos_offset_pos;
	new_pos_offset_pos.x = new_pos.x + player_half_size;
	new_pos_offset_pos.y = new_pos.y + player_half_size;
	t_vec2	new_pos_offset_neg;
	new_pos_offset_neg.x = new_pos.x + -player_half_size;
	new_pos_offset_neg.y = new_pos.y + -player_half_size;

	t_vec2	pos_offset_pos;
	pos_offset_pos.x = e->pos.x + player_half_size;
	pos_offset_pos.y = e->pos.y + player_half_size;
	t_vec2	pos_offset_neg;
	pos_offset_neg.x = e->pos.x + -player_half_size;
	pos_offset_neg.y = e->pos.y + -player_half_size;

	if (ft_strchr(NOT_SOLID_TILES, get_tile(ctx, new_pos_offset_pos.x, pos_offset_pos.y)) && ft_strchr(NOT_SOLID_TILES, get_tile(ctx, new_pos_offset_pos.x, pos_offset_neg.y))
		&& ft_strchr(NOT_SOLID_TILES, get_tile(ctx, new_pos_offset_neg.x, pos_offset_pos.y)) && ft_strchr(NOT_SOLID_TILES, get_tile(ctx, new_pos_offset_neg.x, pos_offset_neg.y)))
		e->pos.x = new_pos.x;

	if (ft_strchr(NOT_SOLID_TILES, get_tile(ctx, pos_offset_pos.x, new_pos_offset_pos.y)) && ft_strchr(NOT_SOLID_TILES, get_tile(ctx, pos_offset_neg.x, new_pos_offset_pos.y))
		&& ft_strchr(NOT_SOLID_TILES, get_tile(ctx, pos_offset_pos.x, new_pos_offset_neg.y)) && ft_strchr(NOT_SOLID_TILES, get_tile(ctx, pos_offset_neg.x, new_pos_offset_neg.y)))
		e->pos.y = new_pos.y;
}
