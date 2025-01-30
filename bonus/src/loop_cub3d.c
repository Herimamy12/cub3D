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
	mlx_hook (data->win->mlx_win, 9, 1L << 21, focus_window_in, data);
	mlx_hook (data->win->mlx_win, 10, 1L << 21, focus_window_out, data);
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
	if (keycode == ETR)
		set_mouse_to_quit (data);
	if (keycode == ESC)
		destroy_data(data);
	if (keycode == SPC && !data->map->door)
		data->map->load_to_open = 1;
	else if (is_cub_event(keycode))
		res = cub_event(keycode, data);
	return (res);
}

int	set_mouse_to_quit(t_data *data)
{
	if (data->cubplay->show_mouse)
		mlx_mouse_hide (data->win->mlx_ptr, data->win->mlx_win);
	else
		mlx_mouse_show (data->win->mlx_ptr, data->win->mlx_win);
	data->cubplay->show_mouse = !data->cubplay->show_mouse;
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	if (data->cubplay->show_mouse)
		return (y);
	if (x > WIDTH / 2)
		data->cubplay->rc_right = 1;
	else if (x < WIDTH / 2)
		data->cubplay->rc_left = 1;
	data->cubplay->reset_mouse = 1;
	return (y);
}
