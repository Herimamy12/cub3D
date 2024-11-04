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

t_scale	*init_dimension(t_map *map)
{
	t_scale	*dim;

	dim = (t_scale *)malloc(sizeof(t_scale));
	if (!dim)
		return (NULL);
	dim->wb = WIDTH / map->width;
	dim->hb = HEIGHT / map->height;
	dim->wp = WIDTH / (map->width + map->width);
	dim->hp = HEIGHT / (map->height + map->height);
	return (dim);
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

t_forb	*init_forb(void)
{
	t_forb	*forb;

	forb = (t_forb *)malloc(sizeof(forb));
	if (!forb)
		return (NULL);
	forb->width  = 0;
	forb->height = 0;
	forb->next = NULL;
	return (forb);
}
