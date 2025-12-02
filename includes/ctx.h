/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:12:21 by mbatty            #+#    #+#             */
/*   Updated: 2025/12/02 23:21:30 by mbatty           ###   ########.fr       */
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

	int		width;
	int		height;
}	t_map;

typedef struct s_img
{
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

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

	float	player_x;
	float	player_y;
	bool	up_input;
	bool	down_input;
	bool	left_input;
	bool	right_input;
}	t_ctx;

# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define ESC_KEY 65307

int	parse_file(t_ctx *ctx);
int	parse_map(t_ctx *ctx);

int	init_mlx(t_ctx *ctx);

int	loop_hook(t_ctx *ctx);
int	key_hook(int keycode, t_ctx *ctx);
int	key_hook_release(int keycode, t_ctx *ctx);
int	close_window(t_ctx *ctx);

#endif
