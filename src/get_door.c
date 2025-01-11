/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:52:16 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/29 10:52:17 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_image	*get_door(t_data *data, int index)
{
	if (index == 0)
		return (data->door->zero);
	else if (index == 1)
		return (data->door->one);
	else if (index == 2)
		return (data->door->two);
	else if (index == 3)
		return (data->door->three);
	else if (index == 4)
		return (data->door->four);
	else if (index == 5)
		return (data->door->five);
	else if (index == 6)
		return (data->door->six);
	else if (index == 7)
		return (data->door->seven);
	else if (index == 8)
		return (data->door->eight);
	return (data->door->zero);
}

t_image	*open_door(t_data *data)
{
	int			tmp;
	static int	now = 0;

	tmp = now / 4000;
	data->map->load_to_close = 0;
	if (let_sleep(&now, 36000))
		return (get_door(data, tmp));
	data->map->door = 1;
	data->map->load_to_open = 0;
	return (get_door(data, tmp));
}

t_image	*close_door(t_data *data)
{
	int			tmp;
	static int	now = 0;

	tmp = now / 4000;
	data->map->door = 0;
	data->map->load_to_open = 0;
	if (let_sleep(&now, 36000))
		return (get_door(data, 8 - tmp));
	data->map->load_to_close = 0;
	return (get_door(data, 8 - tmp));
}
