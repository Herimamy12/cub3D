/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2D_removed_orientation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:45:27 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/08 12:45:28 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	removed_player_orientation(t_win *win, t_player *player)
{
	if (player->old_orientation == 0)
		removed_orientation_east(win, player);
	else if (player->old_orientation == 90)
		removed_orientation_north(win, player);
	else if (player->old_orientation == 180)
		removed_orientation_west(win, player);
	else if (player->old_orientation == 270)
		removed_orientation_south(win, player);
}

void	removed_orientation_east(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->old_posw;
	height = player->old_posh;
	while (width < player->old_posw + 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, BLACK);
		width++ ;
	}
}

void	removed_orientation_north(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->old_posw;
	height = player->old_posh;
	while (height > player->old_posh - 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, BLACK);
		height-- ;
	}
}

void	removed_orientation_south(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->old_posw;
	height = player->old_posh;
	while (height < player->old_posh + 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, BLACK);
		height++ ;
	}
}

void	removed_orientation_west(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->old_posw;
	height = player->old_posh;
	while (width > player->old_posw - 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, BLACK);
		width-- ;
	}
}
