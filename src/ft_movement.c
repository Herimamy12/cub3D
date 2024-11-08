/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:23:22 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/05 23:23:24 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_mov_player(int keycode, t_data *data)
{
	int		ret;
	t_forb	*tmp;

	ret = 1;
	tmp = NULL;
	maj_data_player(data->player);
	if (keycode == NORTH)
		let_mov_north (data, data->forb, tmp);
	else if (keycode == SOUTH)
		let_mov_south (data, data->forb, tmp);
	else if (keycode == EAST)
		let_mov_east (data, data->forb, tmp);
	else if (keycode == WEST)
		let_mov_west (data, data->forb, tmp);
	else if (keycode == RC_LEFT)
		let_rotate_left (data->player);
	else if (keycode == RC_RIGHT)
		let_rotate_right (data->player);
	else
		ret = 0;
	return (ret);
}

int	handle_keypress(int keycode, t_data *data)
{
	int	res;

	res = 0;
	if (keycode == ESC)
		destroy_data (data);
	res = ft_mov_player (keycode, data);
	if (res)
		remove_old_player (data->win, data->player);
	put_player (data->win, data->player);
	return (res);
}

void	maj_data_player(t_player *player)
{
	player->old_posw = player->posw;
	player->old_posh = player->posh;
	player->old_orientation = player->orientation;
}

void	let_rotate_left(t_player *player)
{
	if (player->orientation < 315)
		player->orientation += 45;
	else
		player->orientation = 0;
}

void	let_rotate_right(t_player *player)
{
	if (player->orientation > 0)
		player->orientation -= 45;
	else
		player->orientation = 315;
}
