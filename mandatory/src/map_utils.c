/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:51:57 by herirand          #+#    #+#             */
/*   Updated: 2025/01/12 15:00:58 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	get_long_line(char **map, int x)
{
	int		i;
	size_t	len;

	i = x;
	len = 0;
	while (map[i])
	{
		if (len <= ft_strlen(map[i]))
			len = ft_strlen(map[i]);
		i ++;
	}
	return (len);
}

char	*cpy_map(char *line, size_t x, char c, char s)
{
	size_t		i;
	char		*res;

	if (!line || x == 0)
		return (NULL);
	res = ft_calloc(sizeof(char), x + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < x && line[i] != '\0')
	{
		if (line[i] == ' ')
			res[i] = s;
		else
			res[i] = line[i];
		i ++;
	}
	while (i < x)
		res[i++] = c;
	res[i] = '\0';
	return (res);
}

int	cols_map_verify(char **map, size_t x, size_t len)
{
	size_t	i;
	size_t	j;
	int		heigth;
	char	**res;

	if (!map || x == 0)
		return (0);
	heigth = (count_heigth_map(map) - x) + 1;
	res = ft_calloc(sizeof(char *), heigth);
	i = x;
	j = 0;
	while (map[i])
		res[j++] = cpy_map(map[i++], len, '\0', ' ');
	res[j] = NULL;
	if (verify_cols(res, 0) == 0)
		return (destroy_str(res), 0);
	return (destroy_str(res), 1);
}

int	start_line(char **map)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (map[i] && (is_space_only(map[i]) || !is_line_map(map[i])))
	{
		start ++;
		i ++;
	}
	return (start);
}

char	**map_completed(char **map)
{
	int		i;
	int		j;
	int		len;
	int		start;
	char	**new_map;

	if (!map)
		return (NULL);
	start = start_line(map);
	len = get_long_line(map, start);
	if (cols_map_verify(map, start, len) == 0)
		return (NULL);
	new_map = ft_calloc(sizeof(char *), count_heigth_map(map) + 1);
	if (new_map == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (map[i] && (is_space_only(map[i]) || !is_line_map(map[i])))
		new_map[j++] = lft_strdup(map[i++]);
	while (map[i])
		new_map[j++] = cpy_map(map[i++], len, '1', '1');
	new_map[j] = NULL;
	return (new_map);
}
