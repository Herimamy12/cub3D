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