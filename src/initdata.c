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
	init_cub_int(new);
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

t_image	*alloc_image(void)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->addr = 0;
	img->bpp = 0;
	img->endian = 0;
	img->height = 0;
	img->img = 0;
	img->line_length = 0;
	img->width = 0;
	return (img);
}
