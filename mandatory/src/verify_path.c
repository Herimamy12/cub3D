/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:35:03 by herirand          #+#    #+#             */
/*   Updated: 2025/01/15 15:26:07 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	verify_rgb(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != 32
			&& line[i] != ',' && line[i] != 'F' && line[i] != 'C')
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

	split = ft_split(line, ',');
	if (!split)
		return (destroy_str(split), 0);
	i = 0;
	while (split[i])
	{
		if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0
			|| is_space_only(split[i]))
			return (destroy_str(split), 0);
		i ++;
	}
	if (i != 3)
		return (destroy_str(split), 0);
	return (destroy_str(split), 1);
}

int	verify_path(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "F ", 2) || !ft_strncmp(map[i], "C ", 2))
		{
			if (!verify_rgb(map[i]) || !count_nbr_virg(map[i])
				|| !limits_rgb(map[i]))
				return (0);
		}
		i ++;
	}
	return (1);
}
