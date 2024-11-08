/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player2D_put_orientation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:45:16 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/08 12:45:18 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	put_orientation_east(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->posw;
	height = player->posh;
	while (width < player->posw + 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, WHITE);
		width++ ;
	}
}

void	put_orientation_north(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->posw;
	height = player->posh;
	while (height > player->posh - 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, WHITE);
		height-- ;
	}
}

void	put_orientation_south(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->posw;
	height = player->posh;
	while (height < player->posh + 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, WHITE);
		height++ ;
	}
}

void	put_orientation_west(t_win *win, t_player *player)
{
	int	width;
	int	height;

	width = player->posw;
	height = player->posh;
	while (width > player->posw - 6)
	{
		mlx_pixel_put (win->mlx_ptr, win->mlx_win, width, height, WHITE);
		width-- ;
	}
}

void	put_player_orientation(t_win *win, t_player *player)
{
	if (player->orientation == 0)
		put_orientation_east(win, player);
	else if (player->orientation == 90)
		put_orientation_north(win, player);
	else if (player->orientation == 180)
		put_orientation_west(win, player);
	else if (player->orientation == 270)
		put_orientation_south(win, player);
}
