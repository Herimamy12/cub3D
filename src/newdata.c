/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:51:40 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/04 10:51:43 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_player	*new_player(t_map *map, t_scale *dim)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->posw = get_width_position (map) * dim->wb;
	player->posh = get_height_position (map) * dim->hb;
	player->posw += (dim->wp);
	player->posh += (dim->hp);
	// player->orientation = get_player_orientation (map->map);
	player->old_posw = player->posw;
	player->old_posh = player->posh;
	return (player);
}

t_map	*new_struct_map(char *av)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = new_map (av);
	if (!map)
		return (NULL);
	map->width = count_width_map (map->map);
	map->height = count_heigth_map (map->map);
	return (map);
}

t_win	*new_win(void)
{
	t_win	*win;

	win = (t_win *)malloc(sizeof(t_win));
	if (!win)
		return (NULL);
	win->mlx_ptr = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, NAME);
	if (!win->mlx_ptr || !win->mlx_win)
		return (NULL);
	return (win);
}

t_data	*new_data(char *av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->win = new_win();
	data->map = new_struct_map (av);
	data->dim = init_dimension(data->map);
	data->player = new_player(data->map, data->dim);
	if (!data->win || !data->map)
	{
		destroy_data (data);
		return (NULL);
	}
	return (data);
}
