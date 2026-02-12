/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:19:04 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 14:38:26 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB_H
# define AABB_H

#include "vec2.h"
#include <stdbool.h>

typedef struct s_aabb
{
	t_vec2	pos;
	t_vec2	size;
}	t_aabb;

bool	aabb_collides(t_aabb a, t_aabb b);

t_vec2	aabb_resolve(t_aabb a, t_vec2 d, t_aabb b);

#endif
