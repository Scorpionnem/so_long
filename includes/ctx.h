/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:12:21 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/12 09:13:52 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

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

typedef struct s_map
{
	char	*walls;
	char	*floors;
	char	*collectibles;
	char	*enemies;
	char	exit;
	char	player;
}	t_map;

typedef struct	s_ctx
{
	char	**file;
	char	**map;
	t_map	map_infos;
}	t_ctx;

int	parse_file(t_ctx *ctx);
int	parse_map(t_ctx *ctx);

#endif
