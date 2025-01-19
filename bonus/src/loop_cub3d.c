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
	mlx_hook (data->win->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_hook (data->win->mlx_win, 17, 0, close_win, data);
	mlx_mouse_hide (data->win->mlx_ptr, data->win->mlx_win);
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
	if (keycode == SPC && !data->map->door)
		data->map->load_to_open = 1;
	else if (is_cub_event(keycode))
		res = cub_event(keycode, data);
	return (res);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	if (x > WIDTH / 2)
		data->cubplay->rc_right = 1;
	else if (x < WIDTH / 2)
		data->cubplay->rc_left = 1;
	data->cubplay->reset_mouse = 1;
	return (y);
}

int	rotate_cub_key(int keycode, t_data *data)
{
	if (data->cubplay->rc_left)
	{
		data->cubplay->angle -= S_ROTATION * data->ray->delta_time;
		if (data->cubplay->angle < 0)
			data->cubplay->angle -= 2 * M_PI;
	}
	if (data->cubplay->rc_right)
	{
		data->cubplay->angle += S_ROTATION * data->ray->delta_time;
		if (data->cubplay->angle > 2 * M_PI)
			data->cubplay->angle -= 2 * M_PI;
	}
	return (keycode);
}
