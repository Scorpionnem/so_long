/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:45:15 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 13:45:32 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef enum e_sprite_type
{
	WALL,
	FLOOR,
	COLLECTIBLE,
	ENEMY,
	EXIT,
	PLAYER,
	UNKNOWN
}	t_sprite_type;

typedef struct s_sprite
{
	char			c;
	t_sprite_type	type;

	char			**args;
}	t_sprite;

#endif
