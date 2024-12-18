/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroydata_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:53:19 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/08 10:53:21 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	destroy_image(t_image *img, t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, img->img);
	free(img);
}

void	destroy_anim(t_anim *anim, t_win *win)
{
	destroy_image (anim->zero, win);
	destroy_image (anim->one, win);
	destroy_image (anim->five, win);
	destroy_image (anim->ten, win);
	destroy_image (anim->fiveten, win);
	free (anim);
}
