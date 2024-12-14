/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:32:38 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/14 15:32:39 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_mini	*init_mini(void)
{
	t_mini	*new;

	new = (t_mini *)malloc(sizeof(t_mini));
	if (!new)
		return (NULL);
	new->play_w = 0;
	new->play_h = 0;
	new->offset_w = 0;
	new->offset_h = 0;
	new->angle = 0;
	new->ray_w = 0;
	new->ray_h = 0;
	new->step_w = 0;
	new->step_h = 0;
	return (new);
}
