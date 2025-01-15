/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:23:02 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/01 11:23:05 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	draw_mini_wall(t_data *data)
{
	int	map_w;
	int	map_h;
	int	width;
	int	height;

	height = -1;
	data->mini->offset_w = (int)data->cubplay->width
		- M_WIDTH / (2 * MW_SIZE);
	data->mini->offset_h = (int)data->cubplay->height
		- M_HEIGHT / (2 * MW_SIZE);
	while (++height < M_HEIGHT / MW_SIZE)
	{
		width = -1;
		map_h = height + data->mini->offset_h;
		while (++width < M_WIDTH / MW_SIZE)
		{
			map_w = width + data->mini->offset_w;
			if (map_h >= 0 && map_h < data->map->height
				&& map_w >= 0 && map_w < data->map->width)
			{
				if (data->map->map[map_h][map_w] == '1')
					put_mini_wall(data, width, height);
			}
		}
	}
}

void	put_mini_wall(t_data *data, int width, int height)
{
	int	w;
	int	h;

	h = -1;
	while (++h < MW_SIZE - 1)
	{
		w = -1;
		while (++w < MW_SIZE - 1)
		{
			my_mlx_pixel_put(data->win_tex, M_STARTW + width * MW_SIZE + w,
				M_STARTH + height * MW_SIZE + h, BLACK_WALL);
		}
	}
}

void	draw_border(t_data *data)
{
	int	width;
	int	height;
	int	pixelw;
	int	pixelh;

	height = -2;
	while (++height <= M_HEIGHT)
	{
		width = -2;
		while (++width <= M_WIDTH)
		{
			pixelw = M_STARTW + width;
			pixelh = M_STARTH + height;
			if (height == -1 || width == -1
				|| height == M_HEIGHT || width == M_WIDTH)
				my_mlx_pixel_put(data->win_tex, pixelw, pixelh, WHITE);
			else
				my_mlx_pixel_put(data->win_tex, pixelw, pixelh, GRAY);
		}
	}
}

void	draw_mini_ray(t_data *data)
{
	int		width;
	double	step_x;
	double	step_y;

	width = 0;
	while (width < WIDTH)
	{
		data->ray->angle = data->cubplay->angle - FOV / 2.0
			+ (width / (double)WIDTH) * FOV;
		adjust_ray_angle(data);
		data->ray->width = data->cubplay->width;
		data->ray->height = data->cubplay->height;
		step_x = cos(data->ray->angle);
		step_y = sin(data->ray->angle);
		put_mini_ray(data, step_x, step_y);
		width += 10;
	}
}

void	put_mini_ray(t_data *data, double step_x, double step_y)
{
	int	map_x;
	int	map_y;
	int	pixel_x;
	int	pixel_y;

	while (1)
	{
		map_x = (int)data->ray->width;
		map_y = (int)data->ray->height;
		if (map_x < 0 || map_y < 0 || map_x >= data->map->width)
			break ;
		if (map_y >= data->map->height || data->map->map[map_y][map_x] == '1')
			break ;
		pixel_x = M_STARTW
			+ (data->ray->width - data->mini->offset_w) * MW_SIZE;
		pixel_y = M_STARTH
			+ (data->ray->height - data->mini->offset_h) * MW_SIZE;
		if (pixel_x < M_STARTW || pixel_x >= M_STARTW + M_WIDTH)
			break ;
		if (pixel_y < M_STARTH || pixel_y >= M_STARTH + M_HEIGHT)
			break ;
		my_mlx_pixel_put(data->win_tex, pixel_x, pixel_y, RAY_GRAY);
		data->ray->width += step_x * 0.2;
		data->ray->height += step_y * 0.2;
	}
}
