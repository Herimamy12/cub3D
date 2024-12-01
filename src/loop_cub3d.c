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
	render(data);
	mlx_hook (data->win->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook (data->win->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_hook (data->win->mlx_win, 17, 0, close_win, data);
	mlx_loop (data->win->mlx_ptr);
}

int	handle_keypress(int keycode, t_data *data)
{
	int	res;

	res = 0;
	if (keycode == ESC)
		destroy_data (data);
	else if (is_cub_event(keycode))
		res = cub_event(keycode, data);
	reset_flag(data);
	if (res)
		render(data);
	return (res);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	int			res;
	int			delta_x;
	static int	last_x = -1;

	(void)y;
	if (last_x == -1 || abs(x - last_x) >= 20)
	{
		last_x = x;
		return (0);
	}
	res = 0;
	delta_x = x - last_x;
	if (delta_x > 15)
	{
		last_x = x;
		res = rotate_cub((delta_x - 15) * S_ROTATION, data);
	}
	else if (delta_x < -15)
	{
		last_x = x;
		res = rotate_cub((delta_x + 15) * S_ROTATION, data);
	}
	if (res)
		render(data);
	return (0);
}
