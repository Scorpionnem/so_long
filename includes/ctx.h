/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:12:21 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/11 14:44:49 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef enum e_element_type
{
	FLOOR,
	WALL,
	EXIT,
	COLLECTIBLE,
	UNKNOWN
}	t_element_type;

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
