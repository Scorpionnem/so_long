/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:21:17 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 14:26:54 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

typedef struct	s_ctx t_ctx;

typedef struct s_entity
{
	t_vec2	pos;
	t_vec2	delta;
	t_aabb	bounding;
}	t_entity;

void	entity_update(t_ctx *ctx, t_entity *e);

#endif
