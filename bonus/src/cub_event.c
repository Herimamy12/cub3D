/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:37:30 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/01 13:37:31 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	cub_event(int keycode, t_data *data)
{
	if (keycode == NORTH)
		data->cubplay->up = 1;
	if (keycode == SOUTH)
		data->cubplay->down = 1;
	if (keycode == EAST)
		data->cubplay->right = 1;
	if (keycode == WEST)
		data->cubplay->left = 1;
	if (keycode == RC_LEFT)
	{
		data->cubplay->rc_left = 1;
		data->cubplay->reset_mouse = 0;
	}
	if (keycode == RC_RIGHT)
	{
		data->cubplay->rc_right = 1;
		data->cubplay->reset_mouse = 0;
	}
	return (0);
}

int	is_cub_event(int keycode)
{
	return (keycode == NORTH || keycode == SOUTH
		|| keycode == EAST || keycode == WEST
		|| keycode == RC_LEFT || keycode == RC_RIGHT);
}

int	rotate_cub(float angle, t_data *data)
{
	data->cubplay->angle += angle;
	if (data->cubplay->angle < 0)
		data->cubplay->angle += 2 * M_PI;
	else if (data->cubplay->angle > 2 * M_PI)
		data->cubplay->angle -= 2 * M_PI;
	return (1);
}

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
	mlx_mouse_move (data->win->mlx_ptr, data->win->mlx_win, WIDTH / 2, HEIGHT / 2);
}
