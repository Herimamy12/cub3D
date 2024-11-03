/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:51:18 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/05 20:51:21 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

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

void	loop_cub3d(t_data *data)
{
	fill_screen2d (data);
	put_player (data->win, data->player);
	mlx_hook (data->win->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook (data->win->mlx_win, 17, 0, close_win, data);
	mlx_loop (data->win->mlx_ptr);
}
