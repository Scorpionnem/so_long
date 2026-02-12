/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:39:29 by mbatty            #+#    #+#             */
/*   Updated: 2026/02/12 13:43:34 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctx.h"

int	key_hook(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_ESCAPE)
		close_window(ctx);
	if (keycode == KEY_W)
		ctx->up_input = true;
	if (keycode == KEY_A)
		ctx->left_input = true;
	if (keycode == KEY_S)
		ctx->down_input = true;
	if (keycode == KEY_D)
		ctx->right_input = true;
	return (1);
}

int	key_hook_release(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_W)
		ctx->up_input = false;
	if (keycode == KEY_A)
		ctx->left_input = false;
	if (keycode == KEY_S)
		ctx->down_input = false;
	if (keycode == KEY_D)
		ctx->right_input = false;
	return (1);
}
