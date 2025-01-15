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
	double	last_width;
	double	last_heigth;

	last_width = data->ray->width - (ADDCAST * cos(data->ray->angle));
	last_heigth = data->ray->height - (ADDCAST * sin(data->ray->angle));
	if (data->map->map[(int)data->ray->height][(int)last_width] == '1')
		get_intersec_horizontale(data);
	else
		get_intersec_verticale(data);
	// until
	(void)last_heigth;
}
