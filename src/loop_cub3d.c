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

int	mouvement(t_data *data)
{
	double	h = 0;
	double	w = 0;

	if (data->cubplay->u_d == 1)
	{
		h += sin(data->cubplay->angle) * S_MOUVEMENT;
		w += cos(data->cubplay->angle) * S_MOUVEMENT;
	}
	if (data->cubplay->u_d == -1)
	{
		h -= sin(data->cubplay->angle) * S_MOUVEMENT;
		w -= cos(data->cubplay->angle) * S_MOUVEMENT;
	}
	if (data->cubplay->l_r == 1)
	{
		h -= cos(data->cubplay->angle) * S_MOUVEMENT;
		w += sin(data->cubplay->angle) * S_MOUVEMENT;
	}
	if (data->cubplay->l_r == -1)
	{
		h += cos(data->cubplay->angle) * S_MOUVEMENT;
		w -= sin(data->cubplay->angle) * S_MOUVEMENT;
	}
	h = roundf(h) / 50;
	w = roundf(w) / 50;
	data->cubplay->height += h;
	data->cubplay->width += w;
	return (1);
}

void	reset_flag(t_data *data)
{
	data->cubplay->u_d = 0;
	data->cubplay->l_r = 0;
}

void	loop_cub3d(t_data *data)
{
	render(data);
	mlx_hook (data->win->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook (data->win->mlx_win, 17, 0, close_win, data);
	mlx_loop (data->win->mlx_ptr);
}

int	handle_keypress(int keycode, t_data *data)
{
	int	res;

	res = 0;
	if (keycode == ESC)
		destroy_data (data);
	else if (keycode == RC_LEFT || keycode == RC_RIGHT)
		res = rotate_cub(keycode, data);
	else if (is_cub_event(keycode))
		res = cub_event(keycode, data);
	if (res == 2)
	{
		res = mouvement(data);
		reset_flag(data);
	}
	if (res)
		render(data);
	return (res);
}

int	cub_event(int keycode, t_data *data)
{
	if (keycode == NORTH)
		data->cubplay->u_d = 1;
	else if (keycode == SOUTH)
		data->cubplay->u_d = -1;
	else if (keycode == EAST)
		data->cubplay->l_r = -1;
	else if (keycode == WEST)
		data->cubplay->l_r = 1;
	return 2;
}

int	is_cub_event(int keycode)
{
	return (keycode == NORTH || keycode == SOUTH
		|| keycode == EAST || keycode == WEST);
}

int	rotate_cub(int keycode, t_data *data)
{
	if (keycode == RC_LEFT)
	{
		data->cubplay->angle -= S_ROTATION;
		if (data->cubplay->angle < 0)
			data->cubplay->angle -= 2 * M_PI;
	}
	else if (keycode == RC_RIGHT)
	{
		data->cubplay->angle += S_ROTATION;
		if (data->cubplay->angle > 2 * M_PI)
			data->cubplay->angle -= 2 * M_PI;
	}
	return (1);
}
