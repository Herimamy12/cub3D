/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:03:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/11 22:03:42 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_all_image(t_data *data)
{
	init_image(data, data->wall_tex, "./textures/wall.xpm");
	init_image(data, data->east_tex, "./textures/east.xpm");
	init_image(data, data->west_tex, "./textures/west.xpm");
	init_image(data, data->north_tex, "./textures/north.xpm");
	init_image(data, data->south_tex, "./textures/south.xpm");
}

void	render(t_data *data)
{
	int		width;
	int		height;

	height = -1;
	while (++height < HEIGHT / 2)
	{
		width = -1;
		while (++width < WIDTH)
		{
			my_mlx_pixel_put(data->win_tex, width, height, SKYBLUE);
			my_mlx_pixel_put(data->win_tex,
				width, HEIGHT - height - 1, GREENLAND);
		}
	}
	width = -1;
	while (++width < WIDTH)
	{
		data->ray->angle = data->cubplay->angle - FOV / 2.0
			+ (width / (double)WIDTH) * FOV;
		cast_ray(data, data->ray->angle, width);
	}
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->mlx_win,
		data->win_tex->img, 0, 0);
}
