/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:32:43 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/01 11:32:45 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	draw_mini_map(t_data *data)
{
	draw_border(data);
	draw_mini_wall(data);
	draw_mini_ray(data);
	draw_mini_player(data);
}

void	draw_mini_player(t_data *data)
{
	int	width;
	int	height;
	int	player_pixel_x;
	int	player_pixel_y;

	player_pixel_y = M_STARTH - 1
		+ (data->cubplay->height - data->mini->offset_h) * MW_SIZE;
	height = -1;
	while (++ height < 3)
	{
		width = -1;
		player_pixel_x = (M_STARTW - 1
				+ (data->cubplay->width - data->mini->offset_w) * MW_SIZE);
		while (++ width < 3)
		{
			my_mlx_pixel_put(data->win_tex, player_pixel_x,
				player_pixel_y, RED);
			player_pixel_x++;
		}
		player_pixel_y++;
	}
}
