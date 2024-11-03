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

int	ft_mov_player(int keycode, t_player *player)
{
	int	ret;

	ret = 1;
	player->old_posw = player->posw;
	player->old_posh = player->posh;
	if (keycode == NORTH)
		player->posh -= 2;
	else if (keycode == SOUTH)
		player->posh += 2;
	else if (keycode == EAST)
		player->posw += 2;
	else if (keycode == WEST)
		player->posw -= 2;
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
	res = ft_mov_player (keycode, data->player);
	if (res)
		remove_old_player (data->win, data->player);
	put_player (data->win, data->player);
	return (res);
}
