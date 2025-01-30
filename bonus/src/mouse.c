/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:12:28 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/19 15:12:29 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	reset_mouse(t_data *data)
{
	static int	mouse_x = 0;
	static int	sleep_time = 0;

	if (data->cubplay->mouse_x == mouse_x)
	{
		data->cubplay->rc_left = 0;
		data->cubplay->rc_right = 0;
		data->cubplay->reset_mouse = 0;
	}
	else
	{
		let_sleep(&sleep_time, 50);
		mouse_x = data->cubplay->mouse_x;
	}
	if (!data->cubplay->show_mouse)
		mlx_mouse_move (data->win->mlx_ptr, data->win->mlx_win,
			WIDTH / 2, HEIGHT / 2);
}

int	focus_window_out(t_data *data)
{
	data->cubplay->show_mouse = 1;
	mlx_mouse_show (data->win->mlx_ptr, data->win->mlx_win);
	return (0);
}

int	focus_window_in(t_data *data)
{
	data->cubplay->show_mouse = 0;
	mlx_mouse_hide (data->win->mlx_ptr, data->win->mlx_win);
	return (0);
}
