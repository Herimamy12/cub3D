/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:51:18 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/05 20:51:21 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

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
		printf("t\n");
		// res = cub_event(keycode, data);
	if (res)
		render(data);
	return (res);
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
