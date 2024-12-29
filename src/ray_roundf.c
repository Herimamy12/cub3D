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
		data->tex->wall_tex = get_circl(data);
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
		|| data->map->map[(int)data->ray->height][(int)last_width] == 'P')
		get_intersec_horizontale(data);
	else
		get_intersec_verticale(data);
	if (data->map->map[tmp_heigth][tmp_width] == 'P' && data->map->load_to_open)
		data->tex->wall_tex = open_door(data);
	else if (data->map->map[tmp_heigth][tmp_width] == 'P' && data->map->load_to_close)
		data->tex->wall_tex = close_door(data);
	else if (data->map->map[tmp_heigth][tmp_width] == 'P' && !data->map->door)
		data->tex->wall_tex = data->tex->close_tex;
	else if (data->map->map[(int)last_heigth][(int)last_width] == 'P')
		data->tex->wall_tex = data->tex->door_tex;
}
