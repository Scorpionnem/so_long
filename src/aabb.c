/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:38:27 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 14:53:31 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aabb.h"
#include <stdio.h>

bool	aabb_collides(t_aabb a, t_aabb b)
{
	return (
		a.pos.x < b.pos.x + b.size.x &&
		a.pos.x + a.size.x > b.pos.x &&
		a.pos.y < b.pos.y + b.size.y &&
		a.pos.y + a.size.y > b.pos.y
	);
}

t_vec2	aabb_resolve(t_aabb a, t_vec2 d, t_aabb b)
{
	t_vec2	res;

	a.pos.x += d.x;
	res = d;
	if (aabb_collides(a, b))
	{
		a.pos.x -= d.x;
		res.x = 0;
	}
	a.pos.y += d.y;
	if (aabb_collides(a, b))
		res.y = 0;
	return (res);
}
