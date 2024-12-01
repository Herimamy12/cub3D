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
	double	w;
	double	h;

	w = 0;
	h = 0;
	if (keycode == NORTH)
		data->cubplay->u_d = 1;
	else if (keycode == SOUTH)
		data->cubplay->u_d = -1;
	else if (keycode == EAST)
		data->cubplay->l_r = -1;
	else
		data->cubplay->l_r = 1;
	return (moovement(data, w, h));
}

int	is_cub_event(int keycode)
{
	return (keycode == NORTH || keycode == SOUTH
		|| keycode == EAST || keycode == WEST);
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
