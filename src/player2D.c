/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:52:36 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/03 15:52:40 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	get_width_position(t_map *map)
{
	int	width;
	int height;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (map->map[height][width] == 'N' ||
				map->map[height][width] == 'S' ||
				map->map[height][width] == 'E' ||
				map->map[height][width] == 'W')
				return (width);
			width++;
		}
		height++;
	}
	return (0);
}

int	get_height_position(t_map *map)
{
	int	width;
	int height;

	height = 0;
	while (height < map->height)
	{
		width = 0;
		while (width < map->width)
		{
			if (map->map[height][width] == 'N' ||
				map->map[height][width] == 'S' ||
				map->map[height][width] == 'E' ||
				map->map[height][width] == 'W')
				return (height);
			width++;
		}
		height++;
	}
	return (0);
}
