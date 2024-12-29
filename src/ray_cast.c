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
	int	flag;

	flag = data->ray->door_flag;
	data->ray->distance = 0;
	data->ray->width = data->cubplay->width;
	data->ray->height = data->cubplay->height;
	data->ray->dwidth = cos(data->ray->angle);
	data->ray->dheight = sin(data->ray->angle);
	cast_ray_wall(data, flag);
	roundf_ray(data);
	data->ray->distance *= cos(data->ray->angle - data->cubplay->angle);
	data->wall->height = (int)(HEIGHT / data->ray->distance);
	data->wall->start = (HEIGHT - data->wall->height) / 2;
	data->wall->end = data->wall->start + data->wall->height;
	assign_the_wall(data, width, flag);
}

void	cast_ray_wall(t_data *data, int flag)
{
	int	go;
	int	map_w;
	int	map_h;

	go = 1;
	while (go)
	{
		data->ray->width += data->ray->dwidth * ADDCAST;
		data->ray->height += data->ray->dheight * ADDCAST;
		data->ray->distance += ADDCAST;
		map_w = (int)data->ray->width;
		map_h = (int)data->ray->height;
		if (map_h >= 0 && map_h < HEIGHT && map_w >= 0 && map_w < WIDTH)
		{
			if (data->map->map[map_h] && data->map->map[map_h][map_w]
				&& data->map->map[map_h][map_w] == 'P')
				data->ray->door_flag = 1;
			if (data->map->map[map_h] && data->map->map[map_h][map_w]
				&& (data->map->map[map_h][map_w] == '1' || (flag
				&& data->map->map[map_h][map_w] == 'P'
				&& !data->map->door)))
				break ;
		}
		else
			break ;
	}
}

void	assign_the_wall(t_data *data, int width, int flag)
{
	int	color;
	int	height;

	height = data->wall->start;
	if (data->wall->type == NORTH || data->wall->type == SOUTH)
		data->wall->tex_w = (int)(data->ray->width * data->tex->wall_tex->width)
			% data->tex->wall_tex->width;
	else
		data->wall->tex_w = (int)(data->ray->height * data->tex->wall_tex->width)
			% data->tex->wall_tex->width;
	if (data->wall->type == WEST || data->wall->type == SOUTH)
		data->wall->tex_w = data->tex->wall_tex->width - data->wall->tex_w;
	while (height < data->wall->end)
	{
		data->wall->tex_h = (int)((height - data->wall->start)
				/ (double)data->wall->height * data->tex->wall_tex->height);
		color = get_texture_pixel(data->tex->wall_tex, data->wall->tex_w,
				data->wall->tex_h);
		if (!flag)
			my_mlx_pixel_put(data->win_tex, width, height, color);
		else if (flag && color != 256)
			my_mlx_pixel_put(data->win_tex, width, height, color);
		height++;
	}
	(void)flag;
}
