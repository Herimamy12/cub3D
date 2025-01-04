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

t_map	*new_struct_map(char *av)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = new_map (av);
	if (!map)
		return (NULL);
	map->door = 0;
	map->load_to_open = 0;
	map->load_to_close = 0;
	map->width = count_width_map (map->map);
	map->height = count_heigth_map (map->map);
	map->text_no = get_texture(map->map, "NO");
	map->text_so = get_texture(map->map, "SO");
	map->text_ea = get_texture(map->map, "EA");
	map->text_we = get_texture(map->map, "WE");
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
	data->map = new_struct_map (av);
	if (data->map->map == NULL)
		return (free(data->map), free(data), NULL);
	data->win = new_win();
	data->cubplay = new_cubplay(data->map);
	data->win_tex = new_win_texture(data);
	data->tex = init_tex();
	data->ray = init_ray();
	data->enemy = new_enemy(data->map);
	data->wall = init_wall();
	data->mini = init_mini();
	data->anim = init_anim();
	data->door = init_anim();
	init_all_image(data);
	return (data);
}

t_enemy	*new_enemy(t_map *map)
{
	int		width;
	int		height;
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->width = -1;
	enemy->height = -1;
	height = -1;
	while (++height < map->height && map->map[height])
	{
		width = -1;
		while (++width < map->width && map->map[height][width])
		{
			if (map->map[height][width] == 'E')
			{
				enemy->width = width + 0.5;
				enemy->height = height + 0.5;
			}
		}
	}
	return (enemy);
}

t_wall	*init_wall(void)
{
	t_wall	*new;

	new = (t_wall *)malloc(sizeof(t_wall));
	if (!new)
		return (NULL);
	new->end = 0;
	new->start = 0;
	new->height = 0;
	new->tex_w = 0;
	new->tex_h = 0;
	new->type = 0;
	return (new);
}
