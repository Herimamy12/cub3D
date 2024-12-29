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

void	init_all_image(t_data *data)
{
	init_image(data, data->tex->east_tex, data->map->text_ea);
	init_image(data, data->tex->west_tex, data->map->text_we);
	init_image(data, data->tex->north_tex, data->map->text_no);
	init_image(data, data->tex->south_tex, data->map->text_so);
	init_image(data, data->tex->open_tex, "./textures/open.xpm");
	init_image(data, data->tex->close_tex, "./textures/close.xpm");
	init_anim_image(data);
	init_door_image(data);
}

void	init_door_image(t_data *data)
{
	init_image(data, data->door->zero, "./textures/door/0.xpm");
	init_image(data, data->door->one, "./textures/door/1.xpm");
	init_image(data, data->door->two, "./textures/door/2.xpm");
	init_image(data, data->door->three, "./textures/door/3.xpm");
	init_image(data, data->door->four, "./textures/door/4.xpm");
	init_image(data, data->door->five, "./textures/door/5.xpm");
	init_image(data, data->door->six, "./textures/door/6.xpm");
	init_image(data, data->door->seven, "./textures/door/7.xpm");
	init_image(data, data->door->eight, "./textures/door/8.xpm");
}

void	init_anim_image(t_data *data)
{
	init_image(data, data->anim->zero, "./textures/anime/0.xpm");
	init_image(data, data->anim->one, "./textures/anime/1.xpm");
	init_image(data, data->anim->two, "./textures/anime/2.xpm");
	init_image(data, data->anim->three, "./textures/anime/3.xpm");
	init_image(data, data->anim->four, "./textures/anime/4.xpm");
	init_image(data, data->anim->five, "./textures/anime/5.xpm");
	init_image(data, data->anim->six, "./textures/anime/6.xpm");
	init_image(data, data->anim->seven, "./textures/anime/7.xpm");
	init_image(data, data->anim->eight, "./textures/anime/8.xpm");
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
