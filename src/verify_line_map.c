/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_line_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:27:40 by herirand          #+#    #+#             */
/*   Updated: 2024/11/19 09:20:43 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	is_line_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '1' && line[i] != '0' && line[i] != ' '
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
				&& line[i] != 'W'))
			return (0);
		i ++;
	}
	return (1);
}

int	is_space_only(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i ++;
	}
	return (1);
}

int	is_surround(char *line)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i ++;
		start = i;
		if (!line[start] || line[start] != '1')
			return (0);
		i++;
		while (line[i] && line[i] != ' ')
			i ++;
		end = i -1;
		if (line[end] != '1')
			return (0);
	}
	return (1);
}

int	cnt_player(char *line)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			cnt ++;
		i ++;
	}
	return (cnt);
}

int	is_one_player(char **map, int x)
{
	int	i;
	int	cnt;

	i = x;
	cnt = 0;
	while (map[i])
	{
		cnt += cnt_player(map[i]);
		i ++;
	}
	if (cnt != 1)
		return (0);
	return (1);
}
