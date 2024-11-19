/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroydata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:42:52 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/04 11:42:55 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	destroy_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	destroy_win(t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->mlx_win);
	mlx_destroy_display(win->mlx_ptr);
	free (win->mlx_ptr);
	free (win);
}

void	destroy_map(t_map *map)
{
	if (map->map)
		destroy_str (map->map);
	free (map);
}

void	destroy_data(t_data *data)
{
	if (!data)
		return ;
	destroy_image (data->win_tex, data->win);
	destroy_image (data->north_tex, data->win);
	destroy_image (data->south_tex, data->win);
	destroy_image (data->east_tex, data->win);
	destroy_image (data->west_tex, data->win);
	destroy_win (data->win);
	destroy_map (data->map);
	free (data->cubplay);
	free (data->wall);
	free (data->ray);
	free (data);
	exit (0);
}

int	close_win(t_data *data)
{
	handle_keypress(ESC, data);
	return (1);
}
