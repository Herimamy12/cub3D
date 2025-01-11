/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_roundf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:22:39 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/14 15:22:40 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	get_intersec_verticale(t_data *data)
{
	double	dist_width;
	double	dist_heigth;

	dist_width = fabs(data->ray->width - roundf(data->ray->width));
	data->ray->width = roundf(data->ray->width);
	dist_heigth = tan(data->ray->angle) * dist_width;
	if (cos (data->ray->angle) >= 0)
	{
		data->ray->height -= dist_heigth;
		data->tex->wall_tex = data->tex->east_tex;
		data->wall->type = EAST;
	}
	else
	{
		data->ray->height += dist_heigth;
		data->tex->wall_tex = data->tex->west_tex;
		data->wall->type = WEST;
	}
}

void	get_intersec_horizontale(t_data *data)
{
	double	dist_width;
	double	dist_heigth;

	dist_heigth = fabs(data->ray->height - roundf(data->ray->height));
	data->ray->height = roundf(data->ray->height);
	dist_width = cos(data->ray->angle) / sin(data->ray->angle) * dist_heigth;
	if (sin (data->ray->angle) >= 0)
	{
		data->ray->width -= dist_width;
		data->tex->wall_tex = data->tex->south_tex;
		data->wall->type = SOUTH;
	}
	else
	{
		data->ray->width += dist_width;
		data->tex->wall_tex = data->tex->north_tex;
		data->wall->type = NORTH;
	}
}

void	roundf_ray(t_data *data)
{
	int		tmp_width;
	int		tmp_heigth;
	double	last_width;
	double	last_heigth;

	tmp_width = (int)data->ray->width;
	tmp_heigth = (int)data->ray->height;
	last_width = data->ray->width - (ADDCAST * cos(data->ray->angle));
	last_heigth = data->ray->height - (ADDCAST * sin(data->ray->angle));
	if (data->map->map[(int)data->ray->height][(int)last_width] == '1'
		|| (data->map->map[(int)data->ray->height][(int)last_width] == 'P'
		&& !data->map->door))
		get_intersec_horizontale(data);
	else
		get_intersec_verticale(data);
	if (data->map->map[tmp_heigth][tmp_width] == 'P' && data->map->load_to_open)
		data->tex->wall_tex = open_door(data);
	else if (data->map->map[tmp_heigth][tmp_width] == 'P'
		&& data->map->load_to_close)
		data->tex->wall_tex = close_door(data);
	else if (data->map->map[tmp_heigth][tmp_width] == 'P' && !data->map->door)
		data->tex->wall_tex = data->tex->close_tex;
	else if (data->map->map[(int)last_heigth][(int)last_width] == 'P')
		data->tex->wall_tex = data->tex->door_tex;
}

void	draw_sprite(t_data *data)
{
	int		width;
	double	tex_ratio;

	if (!data->enemy->fput)
		return ;
	width = data->enemy->screen - (data->enemy->screen_h / 2);
	data->tex->wall_tex = get_circl(data);
	data->enemy->screen_h = (int)(HEIGHT / data->enemy->distance);
	data->enemy->start = (HEIGHT - data->enemy->screen_h) / 2;
	data->enemy->end = data->enemy->start + data->enemy->screen_h;
	tex_ratio = (double)
		data->tex->wall_tex->width / (double)data->enemy->screen_h;
	while (width < data->enemy->screen + (data->enemy->screen_h / 2))
	{
		draw_sprite_next(data, tex_ratio, width);
		width++;
	}
}

void	draw_sprite_next(t_data *data, double tex_ratio, int width)
{
	int	color;
	int	heigth;

	heigth = data->enemy->start;
	color = (int)(width - (data->enemy->screen - data->enemy->screen_h / 2));
	data->wall->tex_w = (int)(color * tex_ratio) % data->tex->wall_tex->width;
	while (heigth < data->enemy->end)
	{
		data->wall->tex_h = (int)((heigth - data->enemy->start)
				* data->tex->wall_tex->height / data->enemy->screen_h)
			% data->tex->wall_tex->height;
		color = get_texture_pixel(data->tex->wall_tex, data->wall->tex_w,
				data->wall->tex_h);
		if (color > 0x000000)
			my_mlx_pixel_put(data->win_tex, width, heigth, color);
		heigth++;
	}
}
