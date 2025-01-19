/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:06:14 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/19 13:06:16 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday (&time, NULL) == -1)
		printf ("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec);
}

void	update_time(t_data *data)
{
	double	current_time;

	current_time = (double) clock () / CLOCKS_PER_SEC;
	data->ray->delta_time = (current_time - data->ray->last_time) * 50;
	data->ray->last_time = current_time;
}
