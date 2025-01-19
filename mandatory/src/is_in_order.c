/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:13:30 by herirand          #+#    #+#             */
/*   Updated: 2025/01/18 07:48:16 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	count_path(char **map, char *str, int x)
{
	int	i;
	int	j;
	int	cnt;

	if (!map || !str)
		return (0);
	i = 0;
	cnt = 0;
	while (i < x && map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j ++;
		if (map[i][j] && map[i][j] != 'N' && map[i][j] != 'S'
			&& map[i][j] != 'W' && map[i][j] != 'E' &&
			map[i][j] != 'F' && map[i][j] != 'C')
			return (0);
		if (ft_strncmp(&map[i][j], str, ft_strlen(str)) == 0)
			cnt ++;
		i ++;
	}
	if (cnt != 1)
		return (0);
	return (1);
}

int	verify_count(char **map, int x)
{
	if (count_path(map, "NO ", x) != 1)
		return (0);
	if (count_path(map, "SO ", x) != 1)
		return (0);
	if (count_path(map, "WE ", x) != 1)
		return (0);
	if (count_path(map, "EA ", x) != 1)
		return (0);
	if (count_path(map, "F ", x) != 1)
		return (0);
	if (count_path(map, "C ", x) != 1)
		return (0);
	return (1);
}

int	verify_elem(char **map, int x)
{
	int	i;

	if (map == NULL || map[x] == NULL)
		return (0);
	i = x;
	while (map[i])
	{
		if (!is_line_map(map[i]) || is_space_only(map[i])
			|| !is_surround(map[i]))
			return (0);
		i ++;
	}
	if (!is_one_player(map, x))
		return (0);
	return (1);
}

int	is_map_valid(char **map, int x)
{
	if (verify_count(map, x) == 0)
		return (0);
	if (verify_elem(map, x) == 0)
		return (0);
	if (verify_path(map) == 0)
		return (0);
	return (1);
}

int	is_in_order(char **map)
{
	int	i;
	int	x;

	i = 0;
	while (map[i] && (is_space_only(map[i]) || !is_line_map(map[i])))
		i ++;
	x = i;
	if (map[i + 1] == NULL)
		return (0);
	if (is_map_valid(map, x) == 0)
		return (0);
	return (1);
}
