/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:56:47 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/03 11:56:49 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

char	**new_map(char *av)
{
	int		fd;
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (is_arg_valid(av) == 0)
		return (NULL);
	map = get_map(fd);
	if (is_in_order(map) == 0)
		return (destroy_str(map), NULL);
	close (fd);
	if (!map)
		return (NULL);
	return (map);
}

void	init_anim_image(t_data *data)
{
	init_image(data->win, data->anim->zero, "./textures/anime/0.xpm");
	init_image(data->win, data->anim->one, "./textures/anime/1.xpm");
	init_image(data->win, data->anim->two, "./textures/anime/2.xpm");
	init_image(data->win, data->anim->three, "./textures/anime/3.xpm");
	init_image(data->win, data->anim->four, "./textures/anime/4.xpm");
	init_image(data->win, data->anim->five, "./textures/anime/5.xpm");
	init_image(data->win, data->anim->six, "./textures/anime/6.xpm");
	init_image(data->win, data->anim->seven, "./textures/anime/7.xpm");
	init_image(data->win, data->anim->eight, "./textures/anime/8.xpm");
}

// void	draw_load_to_window(t_data *data)
// {
// 	int x;
// 	int y;
// 	int	width;
// 	int	heigth;
// 	t_image *load;

// 	width = 0;

// 	load = get_circl (data->load);
// 	while (width < WIDTH)
// 	{
// 		height = 0;
// 		x = (width)
// 		while (heigth < HEIGHT)
// 		{
// 			heigth++;
// 		}
// 		width++;
// 	} 


// 	{
// 		int	color;
// 		int	height;

// 		height = data->wall->start;
// 		if (data->tex->wall_tex == data->tex->north_tex || data->tex->wall_tex == data->tex->south_tex)
// 			data->wall->tex_w = (int)(data->ray->width * data->tex->wall_tex->width)
// 				% data->tex->wall_tex->width;
// 		else

// 			data->wall->tex_w = (int)(data->ray->height * data->tex->wall_tex->width)
// 				% data->tex->wall_tex->width;
// 		if (data->wall->type)
// 			data->wall->tex_w = data->tex->wall_tex->width - data->wall->tex_w;

// 		while (height < data->wall->end)
// 		{
// 			data->wall->tex_h = (int)((height - data->wall->start)
// 					/ (double)data->wall->height * data->tex->wall_tex->height);
// 			color = get_texture_pixel(data->tex->wall_tex, data->wall->tex_w,
// 					data->wall->tex_h);
// 			my_mlx_pixel_put(data->win_tex, width, height, color);
// 			height++;
// 		}
// 	}
// }

void	init_all_image(t_data *data)
{
	init_image(data->win, data->tex->east_tex, data->map->text_ea);
	init_image(data->win, data->tex->west_tex, data->map->text_we);
	init_image(data->win, data->tex->north_tex, data->map->text_no);
	init_image(data->win, data->tex->south_tex, data->map->text_so);
	init_anim_image(data);
}

t_cubplay	*new_cubplay(t_map *map)
{
	int			width;
	int			height;
	t_cubplay	*new;

	new = (t_cubplay *)malloc(sizeof(t_cubplay));
	if (!new)
		return (NULL);
	height = -1;
	while (++height < map->height && map->map[height])
	{
		width = -1;
		while (++width < map->width && map->map[height][width])
		{
			if (is_player(map->map[height][width]))
			{
				new->width = width + 0.5;
				new->height = height + 0.5;
				new->angle = get_angle(map->map, width, height);
			}
		}
	}
	return (new);
}

int	is_player(char set)
{
	if (set == 'N')
		return (1);
	else if (set == 'S')
		return (1);
	else if (set == 'W')
		return (1);
	else if (set == 'E')
		return (1);
	return (0);
}

double	get_angle(char **map, int width, int height)
{
	if (map[height][width] == 'N')
		return (DEGNOR);
	else if (map[height][width] == 'S')
		return (DEGSOT);
	else if (map[height][width] == 'W')
		return (DEGWES);
	return (0);
	(void)map;
}
