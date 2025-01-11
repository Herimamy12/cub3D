/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circl_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:20:25 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/18 10:20:27 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_image	*circl_image(t_anim *anim, int index)
{
	if (index == 0)
		return (anim->zero);
	else if (index == 1)
		return (anim->one);
	else if (index == 2)
		return (anim->two);
	else if (index == 3)
		return (anim->three);
	else if (index == 4)
		return (anim->four);
	else if (index == 5)
		return (anim->five);
	else if (index == 6)
		return (anim->six);
	else if (index == 7)
		return (anim->seven);
	else if (index == 8)
		return (anim->eight);
	return (anim->zero);
}

int	let_sleep(int *now, int delay)
{
	if ((*now)++ < delay)
		return (1);
	(*now) = 0;
	return (0);
}

t_image	*get_circl(t_data *data)
{
	int			tmp;
	static int	now = 0;
	static int	index = 0;

	if (let_sleep(&now, SLEEP_TIME / 20000))
		return (circl_image(data->anim, index));
	index ++;
	tmp = index;
	if (index == 9)
		index = 0;
	return (circl_image(data->anim, tmp));
}
