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
	data->east_tex = alloc_image();
	data->west_tex = alloc_image();
	data->north_tex = alloc_image();
	data->south_tex = alloc_image();
	data->ray = init_ray();
	data->wall = init_wall();
	data->mini = init_mini();
	init_all_image(data);
	return (data);
}

t_mini	*init_mini(void)
{
	t_mini	*new;

	new = (t_mini *)malloc(sizeof(t_mini));
	if (!new)
		return (NULL);
	new->play_w = 0;
	new->play_h = 0;
	new->offset_w = 0;
	new->offset_h = 0;
	new->angle = 0;
	new->ray_w = 0;
	new->ray_h = 0;
	new->step_w = 0;
	new->step_h = 0;
	return (new);
}

t_image	*alloc_image(void)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	return (img);
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
	return (new);
}
