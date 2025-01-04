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

int	render(t_data *data)
{
	draw_ceiling_floor (data);
	draw_ray_per_width (data);
	draw_mini_map (data);
	mlx_put_image_to_window (data->win->mlx_ptr, data->win->mlx_win,
		data->win_tex->img, 0, 0);
	moovement(data, 0, 0);
	rotate_cub_key(0, data);
	if (data->map->door)
		wait_and_close(data);
	return (0);
}

void	wait_and_close(t_data *data)
{
	static int	now = 0;

	if (data->map->map[(int)data->cubplay->height]
		[(int)data->cubplay->width] == 'P')
		return ;
	if (let_sleep(&now, SLEEP_TIME / 2))
		return ;
	data->map->load_to_close = 1;
}

void	adjust_ray_angle(t_data *data)
{
	data->ray->angle = fmod (data->ray->angle, 2 * M_PI);
	if (data->ray->angle < 0)
		data->ray->angle += 2 * M_PI;
}

void	draw_ceiling_floor(t_data *data)
{
	int		width;
	int		height;

	height = -1;
	while (++height < HEIGHT / 2)
	{
		width = -1;
		while (++width < WIDTH)
		{
			my_mlx_pixel_put (data->win_tex, width, height, SKYBLUE);
			my_mlx_pixel_put (data->win_tex,
				width, HEIGHT - height - 1, GREENLAND);
		}
	}
}

void	draw_ray_per_width(t_data *data)
{
	int		width;

	width = -1;
	while (++width < WIDTH)
	{
		data->ray->door_flag = 0;
		data->ray->angle = data->cubplay->angle - FOV / 2.0
			+ (width / (double)WIDTH) * FOV;
		adjust_ray_angle(data);
		cast_ray(data, width);
		if (data->ray->door_flag)
			cast_ray(data, width);
	}
}
