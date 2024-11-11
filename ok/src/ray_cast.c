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

void	cast_ray(t_data *data, double ray_angle, int column)
{
	int		hit = 0;

	int		map_x;
	int		map_y;

    int		line_height;
    int		line_start;
    int		line_end;

	int		texture_x;
	int		texture_y;
	int		color;

	double	ray_x = data->cubplay->width;
	double	ray_y = data->cubplay->height;
	double	ray_dx = cos(ray_angle);
	double	ray_dy = sin(ray_angle);

	double	distance = 0;
	double	corrected_distance;

    ray_angle = fmod(ray_angle, 2 * M_PI);
    if (ray_angle < 0)
    	ray_angle += 2 * M_PI;

    while (!hit)
    {
        ray_x += ray_dx * 0.1;
        ray_y += ray_dy * 0.1;
        distance += 0.1;

        map_x = (int)ray_x;
        map_y = (int)ray_y;
        if (map_y >= 0 && map_y < HEIGHT && map_x >= 0 && map_x < WIDTH)
        {
            if (!data->map->map[map_y] || !data->map->map[map_y][map_x] ||
				data->map->map[map_y][map_x] == '1')
                hit = 1;
        }
    }

    corrected_distance = distance * cos(ray_angle - data->cubplay->angle);

    line_height = (int)(HEIGHT / corrected_distance);
    line_start = (HEIGHT - line_height) / 2;
    line_end = line_start + line_height;

    texture_x = (int)(ray_x * 64) % data->wall_tex->width;
    for (int y = line_start; y < line_end; y++)
    {
        texture_y = (int)((y - line_start) / (double)line_height * data->wall_tex->height);
        color = get_texture_pixel(data->wall_tex, texture_x, texture_y);
        my_mlx_pixel_put(data->win_tex, column, y, color);
    }
}
