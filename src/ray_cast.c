/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:01:57 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/11 22:02:00 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	cast_ray(t_data *data, double ray_angle, int width)
{
	int	end;
	int	start;
	int	height;

	data->ray->distance = 0;
	data->ray->dwidth = cos(ray_angle);
	data->ray->dheight = sin(ray_angle);
	data->ray->width = data->cubplay->width;
	data->ray->height = data->cubplay->height;
	ray_angle = adjust_ray_angle(ray_angle);
	cast_ray_wall(data);
	data->ray->distance = data->ray->distance
		* cos(ray_angle - data->cubplay->angle);
	height = (int)(HEIGHT / data->ray->distance);
	start = (HEIGHT - height) / 2;
	end = start + height;
	put_the_wall(data, start, end, width);
}

void	put_the_wall(t_data *data, int start, int end, int width)
{
	int	y;
	int	height;
	int	color;

	y = start;
	height = (int)(HEIGHT / data->ray->distance);
	data->texture_x = (int)(data->ray->width * 64) % data->wall_tex->width;
	while (y < end)
	{
		data->texture_y = (int)((y - start)
				/ (double)height * data->wall_tex->height);
		color = get_texture_pixel(data->wall_tex, data->texture_x,
				data->texture_y);
		my_mlx_pixel_put(data->win_tex, width, y, color);
		y++;
	}
}

void	cast_ray_wall(t_data *data)
{
	int	wall;
	int	map_w;
	int	map_h;

	wall = 0;
	while (!wall)
	{
		data->ray->width += data->ray->dwidth * ADDCAST;
		data->ray->height += data->ray->dheight * ADDCAST;
		data->ray->distance += ADDCAST;
		map_w = (int)data->ray->width;
		map_h = (int)data->ray->height;
		if (map_h >= 0 && map_h < HEIGHT && map_w >= 0 && map_w < WIDTH)
		{
			if (!data->map->map[map_h] || !data->map->map[map_h][map_w] ||
				data->map->map[map_h][map_w] == '1')
				wall = 1;
		}
	}
}

double	adjust_ray_angle(double ray_angle)
{
	ray_angle = fmod(ray_angle, 2 * M_PI);
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	return (ray_angle);
}
