/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananarivo>  #+#  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-18 16:09:56 by herirand          #+#    #+#             */
/*   Updated: 2024/11/19 09:21:19 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

char	*texture(char *line)
{
	int	i;

	if (line == NULL)
		return (NULL);
	i = 0;
	while (line[i] && line[i] == ' ')
		i ++;
	if (line[i] == '\0')
		return (NULL);
	return (&line[i]);
}

char	*get_texture(char **map, char *text)
{
	int	i;

	i = 0;
	if (map == NULL)
		return (NULL);
	while (map[i])
	{
		if (ft_strncmp(map[i], text, ft_strlen(text)) == 0)
			return (texture(&map[i][2]));
		i ++;
	}
	return (NULL);
}

int	is_arg_valid(char *av)
{
	int		i;
	int		len;

	len = ft_strlen(av);
	if (len <= 4)
		return (0);
	if (lft_strcmp(&av[len - 4], ".cub") != 0)
	{
		printf("ato\n");
		return (0);
	}
	i = 0;
	while (i < len - 4)
	{
		if (av[i] == '\0')
			return (0);
		i ++;
	}
	return (1);
}
