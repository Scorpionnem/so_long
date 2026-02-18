/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:12:21 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/18 12:37:27 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <sys/time.h>

#include "key_codes.h"
#include "sprite.h"
#include "img.h"
#include "aabb.h"
#include "vec2.h"
#include "entity.h"

typedef struct s_map
{
	char	*walls;
	char	*floors;
	char	*collectibles;
	char	*enemies;
	char	exit;
	char	player;

	int		width;
	int		height;
}	t_map;

typedef struct	s_shake
{
	bool	active;

	float	duration;
	
	float	timer;
	float	force;
	float	speed;
	int		x;
	int		y;
}	t_shake;

typedef struct	s_ctx
{
	char	**file;
	char	**map;
	t_map	map_infos;

	void		*mlx;
	void		*mlx_win;
	t_img		img;
	int			window_width;
	int			window_height;

	t_entity	player;

	bool	up_input;
	bool	down_input;
	bool	left_input;
	bool	right_input;

	double	delta;
	double	last_frame;
	t_shake	shake;
}	t_ctx;

#define TILE_SIZE 64
#define PLAYER_SIZE 48

int	parse_file(t_ctx *ctx);
int	parse_map(t_ctx *ctx);

int	init_mlx(t_ctx *ctx);

int	loop_hook(t_ctx *ctx);
int	key_hook(int keycode, t_ctx *ctx);
int	key_hook_release(int keycode, t_ctx *ctx);
int	close_window(t_ctx *ctx);

void	ctx_delete(t_ctx *ctx);
int		ctx_init(t_ctx *ctx, int ac, char **av);

void	update_delta(t_ctx *ctx);

#endif
