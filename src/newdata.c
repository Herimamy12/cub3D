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

t_player	*new_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->posi = WIDTH / 2;
	player->posj = HEIGHT / 2;
	player->old_posi = WIDTH / 2;
	player->old_posj = HEIGHT / 2;
	return (player);
}

char	**new_map(char *av)
{
	int		fd;
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = get_map(fd);
	close (fd);
	if (!map)
		return (NULL);
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
	data->map = new_map(av);
	data->dim = init_dimension();
	data->player = new_player();
	if (!data->win || !data->map)
	{
		destroy_data (data);
		return (NULL);
	}
	return (data);
}
