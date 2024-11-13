/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:47:50 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/13 22:47:53 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	movement(t_data *data, double w, double h)
{
	if (data->cubplay->u_d == 1)
	{
		h += sin(data->cubplay->angle) * S_MOVEMENT;
		w += cos(data->cubplay->angle) * S_MOVEMENT;
	}
	else if (data->cubplay->u_d == -1)
	{
		h -= sin(data->cubplay->angle) * S_MOVEMENT;
		w -= cos(data->cubplay->angle) * S_MOVEMENT;
	}
	else if (data->cubplay->l_r == 1)
	{
		h -= cos(data->cubplay->angle) * S_MOVEMENT;
		w += sin(data->cubplay->angle) * S_MOVEMENT;
	}
	else
	{
		h += cos(data->cubplay->angle) * S_MOVEMENT;
		w -= sin(data->cubplay->angle) * S_MOVEMENT;
	}
	if (is_wall (data, w, h))
		return (0);
	return (1);
}

int	is_wall(t_data *data, double w, double h)
{
	int	map_w;
	int	map_h;

	w = (roundf(w) / 25) + data->cubplay->width;
	h = (roundf(h) / 25) + data->cubplay->height;
	map_w = (int)w;
	map_h = (int)h;
	if (data->map->map[map_h][map_w] == '1')
		return (1);
	// else if (data->map->map[map_h + 1][map_w + 1] == '1')
	// 	return (1);
	data->cubplay->height = h;
	data->cubplay->width = w;
	return (0);
}

void	reset_flag(t_data *data)
{
	data->cubplay->u_d = 0;
	data->cubplay->l_r = 0;
}
