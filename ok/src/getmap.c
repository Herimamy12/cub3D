/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:13:25 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/04 22:13:28 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

char	**get_map(int fd)
{
	char	*tmp;
	char	*line;
	char	**map;

	tmp = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp (line, "\n"))
			line = ft_strdup (line, " \n");
		tmp = ft_strjoin(tmp, line);
		free (line);
		line = get_next_line(fd);
	}
	map = ft_split(tmp, '\n');
	free (tmp);
	free (line);
	return (map);
}

int	count_heigth_map(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	count_width_map(char **map)
{
	int	count;
	int	width;
	int	height;

	count = 0;
	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
			width++;
		if (count < width)
			count = width;
		height++;
	}
	return (count);
}
