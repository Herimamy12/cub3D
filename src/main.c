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
		return (1);
	data = new_data (av[1]);
	if (!data)
		return (1);
	// print_map (data->map);
	loop_cub3d (data);
	return (0);
}
