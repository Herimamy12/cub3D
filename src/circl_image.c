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
		return (anim->five);
	else if (index == 3)
		return (anim->ten);
	else if (index == 4)
		return (anim->fiveten);
	return (anim->zero);
}

int	let_sleep(void)
{
	static int	sleep_time = 0;

	sleep_time ++;
	if (sleep_time < SLEEP_TIME)
		return (1);
	sleep_time = 0;
	return (0);
}

t_image	*get_circl(t_data *data)
{
	int			tmp;
	static int	index = 0;

	if (let_sleep())
		return (circl_image(data->anim, index));
	index ++;
	tmp = index;
	if (index == 5)
		index = 0;
	return (circl_image(data->anim, tmp));
}
