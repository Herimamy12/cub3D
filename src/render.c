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
	draw_sprite (data);
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
			my_mlx_pixel_put (data->win_tex, width, height, data->rgb_c);
			my_mlx_pixel_put (data->win_tex,
				width, HEIGHT - height - 1, data->rgb_f);
		}
	}
}

void	draw_ray_per_width(t_data *data)
{
	int		width;

	width = -1;
	data->enemy->fput = 0;
	while (++width < WIDTH)
	{
		data->ray->fdoor = 0;
		data->ray->fsprite = 0;
		data->ray->door_flag = 0;
		data->ray->sprite_flag = 0;
		data->ray->angle = data->cubplay->angle - FOV / 2.0
			+ (width / (double)WIDTH) * FOV;
		adjust_ray_angle(data);
		cast_ray(data, width);
		if (data->ray->door_flag || data->ray->sprite_flag)
			cast_ray(data, width);
	}
}

void	draw_sprite(t_data *data)
{
	int	width;
	int	heigth;
	int	color;
	double texture_width_ratio;

	if (!data->enemy->fput)
		return ;
	width = data->enemy->screen - (data->enemy->screen_h / 2);
	data->tex->wall_tex = get_circl(data);
	data->enemy->screen_h = (int)(HEIGHT / data->enemy->distance);
	data->enemy->start = (HEIGHT - data->enemy->screen_h) / 2;
	data->enemy->end = data->enemy->start + data->enemy->screen_h;
	texture_width_ratio = (double)data->tex->wall_tex->width / (double)data->enemy->screen_h;
	while (width < data->enemy->screen + (data->enemy->screen_h / 2))
	{
		heigth = data->enemy->start;
		color = (int)(width - (data->enemy->screen - data->enemy->screen_h / 2));
		data->wall->tex_w = (int)(color * texture_width_ratio) % data->tex->wall_tex->width;
		while (heigth < data->enemy->end)
		{
			data->wall->tex_h = (int)((heigth - data->enemy->start) * data->tex->wall_tex->height / data->enemy->screen_h) % data->tex->wall_tex->height;
			color = get_texture_pixel(data->tex->wall_tex, data->wall->tex_w, data->wall->tex_h);
			if (color > 0x000000)
				my_mlx_pixel_put(data->win_tex, width, heigth, color);
			heigth++;
		}
		width++;
	}
}
