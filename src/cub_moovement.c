/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moovement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:43:47 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/18 20:43:51 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	moovement(t_data *data, double w, double h)
{
	if (data->cubplay->u_d == 1)
	{
		h += sin(data->cubplay->angle) * S_MOOVEMENT;
		w += cos(data->cubplay->angle) * S_MOOVEMENT;
	}
	else if (data->cubplay->u_d == -1)
	{
		h -= sin(data->cubplay->angle) * S_MOOVEMENT;
		w -= cos(data->cubplay->angle) * S_MOOVEMENT;
	}
	else if (data->cubplay->l_r == 1)
	{
		h -= cos(data->cubplay->angle) * S_MOOVEMENT;
		w += sin(data->cubplay->angle) * S_MOOVEMENT;
	}
	else
	{
		h += cos(data->cubplay->angle) * S_MOOVEMENT;
		w -= sin(data->cubplay->angle) * S_MOOVEMENT;
	}
	if (is_wall (data, w, h))
		return (0);
	return (1);
}

int	is_wall(t_data *data, double w, double h)
{
	int	map_w;
	int	map_h;

	map_w = (int)((roundf(w) / 5) + data->cubplay->width);
	map_h = (int)((roundf(h) / 5) + data->cubplay->height);
	if (data->map->map[map_h][map_w] == '1')
		return (1);
	w = (roundf(w) / 25) + data->cubplay->width;
	h = (roundf(h) / 25) + data->cubplay->height;
	data->cubplay->height = h;
	data->cubplay->width = w;
	return (0);
}

void	reset_flag(t_data *data)
{
	data->cubplay->u_d = 0;
	data->cubplay->l_r = 0;
}
