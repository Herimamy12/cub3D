/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen2D.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:09:28 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/03 12:09:36 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	fill_brick_wall2d(t_data *data, int height, int width)
{
	int	limw;
	int	limh;
	int	initw;
	int	inith;

	inith = height * data->dim->hb;
	limw = (width + 1) * data->dim->wb;
	limh = (height + 1) * data->dim->hb;
	while (inith < limh)
	{
		initw = width * data->dim->wb;
		while (initw < limw)
		{
			mlx_pixel_put (data->win->mlx_ptr, data->win->mlx_win,
				initw, inith, WHITE);
			initw++;
		}
		inith++;
	}
}

void	fill_screen2d(t_data *data)
{
	int	width;
	int	height;

	height = 0;
	while (data->map->map[height])
	{
		width = 0;
		while (data->map->map[height][width])
		{
			if (data->map->map[height][width] == '1')
			{
				forb_addback (&(data->forb), new_forb (width, height));
				// fill_brick_wall2d (data, height, width);
			}
			width++;
		}
		height++;
	}
}
