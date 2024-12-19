/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_load_anim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:24:43 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/19 12:24:45 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_load	*new_load(void)
{
	t_load	*load;

	load = (t_load *)malloc(sizeof(t_load));
	if (!load)
		return (NULL);
	load->win = new_win();
	load->win_tex = new_win_texture(load->win);
	load->anim = init_anim();
	init_all_load(load);
	return (load);
}

void	init_all_load(t_load *load)
{
	init_image(load->win, load->anim->zero, "./textures/load/0.xpm");
	init_image(load->win, load->anim->one, "./textures/load/1.xpm");
	init_image(load->win, load->anim->two, "./textures/load/2.xpm");
	init_image(load->win, load->anim->three, "./textures/load/3.xpm");
	init_image(load->win, load->anim->four, "./textures/load/4.xpm");
	init_image(load->win, load->anim->five, "./textures/load/5.xpm");
	init_image(load->win, load->anim->six, "./textures/load/6.xpm");
	init_image(load->win, load->anim->seven, "./textures/load/7.xpm");
	init_image(load->win, load->anim->eight, "./textures/load/8.xpm");
}
