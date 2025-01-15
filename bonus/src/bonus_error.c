/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:38:48 by herirand          #+#    #+#             */
/*   Updated: 2025/01/15 12:40:29 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	is_one_fire(char **map, int x)
{
	int	i;
	int	j;
	int	cnt;

	i = x;
	cnt = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'B')
				cnt++;
			j++;
		}
		i ++;
	}
	if (cnt != 1)
		return (0);
	return (1);
}

int	good_door(char **map, int x)
{
	int	i;
	int	j;

	i = x;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (!verify_cols_door(map, i, j)
					&& !verify_line_door(map, i, j))
					return (0);
			}
			j++;
		}
		i ++;
	}
	return (1);
}

int	verify_cols_door(char **map, int i, int j)
{
	return (
		(map[i - 1] && map[i + 1])
		&& (map[i][j - 1] && map[i][j + 1])
		&& (map[i][j - 1] == '1' && map[i][j + 1] == '1')
		&& (map[i - 1][j] == '0' && map[i + 1][j] == '0')
	);
}

int	verify_line_door(char **map, int i, int j)
{
	return (
		(map[i - 1] && map[i + 1])
		&& (map[i][j - 1] && map[i][j + 1])
		&& (map[i - 1][j] == '1' && map[i + 1][j] == '1')
		&& (map[i][j - 1] == '0' && map[i][j + 1] == '0')
	);
}

int	bonus_valid(char **map, int x)
{
	if (!is_one_fire(map, x))
		return (0);
	if (!good_door(map, x))
		return (0);
	return (1);
}
