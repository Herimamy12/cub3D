/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surround.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:23 by herirand          #+#    #+#             */
/*   Updated: 2025/01/12 14:55:10 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	len_cols(char **map, int x, int y)
{
	int	len;
	int	i;

	i = x;
	len = 0;
	while (map[i] != NULL && map[i][y] != '\0')
	{
		len ++;
		i ++;
	}
	return (len);
}

void	find_limit(char **map, int x, int j, t_limits *limits)
{
	int	i;
	int	len;

	i = x;
	limits->start = -1;
	limits->end = -1;
	len = len_cols(map, x, j) + x;
	while (map[i] && i < len)
	{
		while (map[i] && map[i][j] == ' ' && i < len)
			i++;
		if (!map[i])
			break ;
		if (limits->start == -1)
			limits->start = i;
		if (map[i] && map[i][j] && map[i][j] != ' ' && i < len)
			limits->end = i;
		i++;
	}
}

int	verify_limits(char **map, t_limits *limits, int j)
{
	if (limits->start == -1)
		return (1);
	if ((limits->start != -1 && map[limits->start][j] != '1') ||
		(map[limits->end][j] && map[limits->end][j] != '1'))
		return (0);
	return (1);
}

int	verify_cols(char **map, int x)
{
	int			j;
	t_limits	limits;

	j = 0;
	while (map[x][j])
	{
		find_limit(map, x, j, &limits);
		if (!(verify_limits(map, &limits, j)))
			return (0);
		j++;
	}
	return (1);
}
