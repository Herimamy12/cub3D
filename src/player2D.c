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
	int	height;

	height = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
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
	int	height;

	height = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
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

int	get_player_orientation(t_map *map)
{
	int	width;
	int	height;

	height = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
		{
			if (map->map[height][width] == 'N')
				return (DEGNO);
			else if (map->map[height][width] == 'S')
				return (DEGSO);
			else if (map->map[height][width] == 'E')
				return (DEGEA);
			else if (map->map[height][width] == 'W')
				return (DEGWE);
			width++;
		}
		height++;
	}
	return (DEGERR);
}

void	remove_old_player(t_win *win, t_player *player)
{
	int	width;
	int	height;

	height = player->old_posw - 2;
	while (height < player->old_posw + 3)
	{
		width = player->old_posh - 2;
		while (width < player->old_posh + 3)
		{
			mlx_pixel_put (win->mlx_ptr, win->mlx_win, height, width, BLACK);
			width++;
		}
		height++;
	}
}

void	put_player(t_win *win, t_player *player)
{
	int	width;
	int	height;

	height = player->posw - 2;
	while (height < player->posw + 3)
	{
		width = player->posh - 2;
		while (width < player->posh + 3)
		{
			mlx_pixel_put (win->mlx_ptr, win->mlx_win, height, width, WHITE);
			width++;
		}
		height++;
	}
}
