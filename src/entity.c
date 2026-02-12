/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:22:36 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 14:54:07 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

void	entity_update(t_ctx *ctx, t_entity *e)
{
	t_vec2	delta;

	delta = e->delta;

	t_aabb	a;
	a.pos.x = e->pos.x;
	a.pos.y = e->pos.y;
	t_vec2	size;
	size.x = 0.75 / TILE_SIZE;
	size.y = 0.75 / TILE_SIZE;
	a.size = size;

	t_aabb	b;
	size.x = 3;
	size.y = 3;
	b.pos = size;
	size.x = 1 / TILE_SIZE;
	size.y = 1 / TILE_SIZE;
	b.size = size;
	delta = aabb_resolve(a, delta, b);

	e->pos.x += delta.x * ctx->delta;
	e->pos.y += delta.y * ctx->delta;
}
