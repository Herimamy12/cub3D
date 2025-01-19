/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:30:58 by herirand          #+#    #+#             */
/*   Updated: 2025/01/17 13:03:42 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_color	*init_color(void)
{
	t_color	*color;

	color = ft_calloc(sizeof(t_color), 1);
	if (color == NULL)
		return (NULL);
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	return (color);
}

int	parse_color(t_color *color, char *line)
{
	char	**split;

	split = NULL;
	if (!color || !line)
		return (0);
	split = ft_split(line, ',');
	if (split == NULL)
		return (destroy_str(split), 0);
	color->red = ft_atoi(split[0]);
	color->green = ft_atoi(split[1]);
	color->blue = ft_atoi(split[2]);
	destroy_str(split);
	return (convers_color(color));
}

int	get_color(t_color *color, char	**map, char *colors)
{
	int	i;
	int	j;

	if (map == NULL || color == NULL)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j ++;
		if (ft_strncmp(&map[i][j], colors, ft_strlen(colors)) == 0)
			return (parse_color(color, &(map[i][j + 1])));
		i ++;
	}
	return (0);
}

int	convers_color(t_color *color)
{
	if (color == NULL)
		return (0);
	return ((color->red << 16) | (color->green << 8) | color->blue);
}
