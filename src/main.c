/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:13:56 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/03 23:13:58 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		write(2, "Error : argument\n", 17);
		return (1);
	}
	data = new_data (av[1]);
	if (!data)
	{
		write(2, "Error : map\n", 12);
		return (1);
	}
	get_color(data->map->map, "F");
	loop_cub3d (data);
	return (0);
}
