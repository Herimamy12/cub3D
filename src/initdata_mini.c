/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:32:38 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/14 15:32:39 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_mini	*init_mini(void)
{
	t_mini	*new;

	new = (t_mini *)malloc(sizeof(t_mini));
	if (!new)
		return (NULL);
	new->play_w = 0;
	new->play_h = 0;
	new->offset_w = 0;
	new->offset_h = 0;
	new->angle = 0;
	new->ray_w = 0;
	new->ray_h = 0;
	new->step_w = 0;
	new->step_h = 0;
	return (new);
}

void	init_cub_int(t_cubplay *new)
{
	new->up = 0;
	new->down = 0;
	new->left = 0;
	new->right = 0;
	new->rc_left = 0;
	new->rc_right = 0;
}

void	init_enemy_int(t_enemy *enemy)
{
	enemy->fput = 0;
	enemy->screen = 0;
	enemy->screen_h = 0;
	enemy->distance = 0;
	enemy->start = 0;
	enemy->end = 0;
}

int	is_hit_enemy(t_data *data, int width)
{
	if (fabs(data->enemy->height - data->ray->height) < ADDCAST
		&& fabs(data->enemy->width - data->ray->width) < ADDCAST)
	{
		data->enemy->fput = 1;
		data->enemy->screen = width;
		data->enemy->distance = data->ray->distance;
		return (1);
	}
	return (0);
}
