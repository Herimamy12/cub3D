/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:03 by herirand          #+#    #+#             */
/*   Updated: 2025/01/17 14:26:05 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	is_all_digit(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i ++;
		while (line[i] && ft_isdigit(line[i]))
			i ++;
		while (line[i] && line[i] == ' ')
			i ++;
		if (line[i] && ft_isdigit(line[i]))
			return (0);
	}
	return (1);
}

int	verify_rgb(char *line)
{
	int	i;
	int	cnt;

	if (!line)
		return (0);
	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != 32
			&& line[i] != ',')
			return (0);
		if (line[i] == ',')
			cnt ++;
		i ++;
	}
	if (cnt != 2)
		return (0);
	return (1);
}

int	count_nbr_virg(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == ',')
			cnt++;
		i ++;
	}
	if (cnt != 2)
		return (0);
	return (1);
}

int	limits_rgb(char *line)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(&line[1], ',');
	if (!split)
		return (destroy_str(split), 0);
	i = 0;
	while (split[i])
	{
		if (!is_all_digit(split[i]))
			return (destroy_str(split), 0);
		j = 0;
		while (split[i][j] == ' ')
			j ++;
		if (ft_atoi(&split[i][j]) > 255 || ft_atoi(&split[i][j]) < 0
			|| is_space_only(split[i]) || split[i][j] == '\0')
			return (destroy_str(split), 0);
		i ++;
	}
	if (i != 3)
		return (destroy_str(split), 0);
	return (destroy_str(split), 1);
}

int	verify_path(char **map)
{
	int	j;
	int	i;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j ++;
		if (!ft_strncmp(&map[i][j], "F ", 2)
			|| !ft_strncmp(&map[i][j], "C ", 2))
		{
			if (!verify_rgb(&map[i][j + 1]) || !count_nbr_virg(&map[i][j])
				|| !limits_rgb(&map[i][j]))
				return (0);
		}
		i ++;
	}
	return (1);
}
