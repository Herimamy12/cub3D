/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:51:18 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/13 11:24:23 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	loop_cub3d(t_data *data)
{
	mlx_hook (data->win->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook (data->win->mlx_win, 3, 1L << 1, handle_keyrelease, data);
	mlx_hook (data->win->mlx_win, 17, 0, close_win, data);
	mlx_loop_hook (data->win->mlx_ptr, render, data);
	mlx_loop (data->win->mlx_ptr);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == NORTH)
		data->cubplay->up = 0;
	if (keycode == SOUTH)
		data->cubplay->down = 0;
	if (keycode == WEST)
		data->cubplay->left = 0;
	if (keycode == EAST)
		data->cubplay->right = 0;
	if (keycode == RC_LEFT)
		data->cubplay->rc_left = 0;
	if (keycode == RC_RIGHT)
		data->cubplay->rc_right = 0;
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	int	res;

	res = 0;
	if (keycode == ESC)
		destroy_data(data);
	else if (is_cub_event(keycode))
		res = cub_event(keycode, data);
	return (res);
}

int	rotate_cub_key(int keycode, t_data *data)
{
	if (data->cubplay->rc_left)
	{
		data->cubplay->angle -= S_ROTATION;
		if (data->cubplay->angle < 0)
			data->cubplay->angle -= 2 * M_PI;
	}
	if (data->cubplay->rc_right)
	{
		data->cubplay->angle += S_ROTATION;
		if (data->cubplay->angle > 2 * M_PI)
			data->cubplay->angle -= 2 * M_PI;
	}
	return (keycode);
}
