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
	// t_load	*load;
	t_data	*data;

	if (ac != 2)
		return (write(2, "Error : argument\n", 17), 1);
	// load = new_load ();
	// if (!load)
	// 	return (write (2, "Error loading game\n", 19), 1);
	data = new_data (av[1]);
	if (!data)
		return (write(2, "Error : creation data\n", 12), 1);
	get_color(data->map->map, "F");
	loop_cub3d (data);
	return (0);
}
