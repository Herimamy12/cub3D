/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:37:48 by herirand          #+#    #+#             */
/*   Updated: 2024/11/19 10:32:04 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

unsigned long hexadecima(unsigned long nb)
{
	char	*s;
	int		res;

	res = 0;
	s = "0123456789ABCDEF";
	if (nb > 15)
		hexadecima(nb / 16);
	res = (res * 10) + s[nb % 16];
	return (res);
}

int	convert_color(char *line)
{
	int		i;
	int		res;
	char	**color;

	res = 0;
	color = NULL;
	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] == ' ' && !ft_isdigit(line[i]))
		i ++;
	if (line[i] == '\0')
		return (0);
	color = ft_split(&line[i], ',');
	if (!color)
		return (0);
	i = 0;
	while (color[i])
	{
		// printf("line[%d] == {%s}\n", i, color[i]);
		res = (res * 10) + hexadecima(line[i]);
		// printf("res == {%x}\n", res);
		i ++;
	}
	// printf("res == {%x}\n", res);
	// printf("line == {%s}\n", &line[i]);
	return (1);
}

int	get_color(char	**map, char *color)
{
	int	i;

	if (map == NULL || color == NULL)
		return (0);
	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], color, ft_strlen(color)) == 0)
			return (convert_color(&map[i][1]));
		i ++;
	}
	return (0);
}
