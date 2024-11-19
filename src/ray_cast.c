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

void	cast_ray(t_data *data, int width)
{
	data->ray->distance = 0;
	data->ray->width = data->cubplay->width;
	data->ray->height = data->cubplay->height;
	data->ray->dwidth = cos(data->ray->angle);
	data->ray->dheight = sin(data->ray->angle);
	cast_ray_wall(data);
	data->ray->distance *= cos(data->ray->angle - data->cubplay->angle);
	data->wall->height = (int)(HEIGHT / data->ray->distance);
	data->wall->start = (HEIGHT - data->wall->height) / 2;
	data->wall->end = data->wall->start + data->wall->height;
	assign_the_wall(data, width);
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
			if (data->map->map[map_h] && data->map->map[map_h][map_w]
				&& data->map->map[map_h][map_w] == '1')
			{
				wall = 1;
				get_wall_texture(data, map_w, map_h);
			}
		}
		else
			break ;
	}
}

void	get_wall_texture(t_data *data, int map_w, int map_h)
{
	double	hit_x;
	double	hit_y;

	hit_x = data->ray->width - map_w;
	hit_y = data->ray->height - map_h;
	if (fabs(hit_x) > fabs(hit_y))
	{
		if (hit_x > 0.9950)
			data->wall_tex = data->west_tex;
		else
			data->wall_tex = data->south_tex;
	}
	else
	{
		if (hit_y > 0.9950)
			data->wall_tex = data->north_tex;
		else
			data->wall_tex = data->east_tex;
	}
}

void	assign_the_wall(t_data *data, int width)
{
	int	color;
	int	height;

	height = data->wall->start;
	if (data->wall_tex == data->north_tex || data->wall_tex == data->south_tex)
		data->wall->tex_w = (int)(data->ray->width * data->wall_tex->width)
			% data->wall_tex->width;
	else
		data->wall->tex_w = (int)(data->ray->height * data->wall_tex->width)
			% data->wall_tex->width;
	while (height < data->wall->end)
	{
		data->wall->tex_h = (int)((height - data->wall->start)
				/ (double)data->wall->height * data->wall_tex->height);
		color = get_texture_pixel(data->wall_tex, data->wall->tex_w,
				data->wall->tex_h);
		// my_mlx_pixel_put(data->win_tex, width, height, color);
		height++;
	}
	// à supprimer
	(void)color;
	(void)width;
}
