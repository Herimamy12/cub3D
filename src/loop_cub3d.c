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
	int	col;
	int	line;

	line = player->old_posi - 2;
	while (line < player->old_posi + 3)
	{
		col = player->old_posj - 2;
		while (col < player->old_posj + 3)
		{
			mlx_pixel_put (win->mlx_ptr, win->mlx_win, line, col, BLACK);
			col++;
		}
		line++;
	}
}

void	put_player(t_win *win, t_player *player)
{
	int	col;
	int	line;

	line = player->posi - 2;
	while (line < player->posi + 3)
	{
		col = player->posj - 2;
		while (col < player->posj + 3)
		{
			mlx_pixel_put (win->mlx_ptr, win->mlx_win, line, col, WHITE);
			col++;
		}
		line++;
	}
}

void	loop_cub3d(t_data *data)
{
	put_player (data->win, data->player);
	mlx_hook (data->win->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook (data->win->mlx_win, 17, 0, close_win, data);
	mlx_loop (data->win->mlx_ptr);
}
