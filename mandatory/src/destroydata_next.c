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
	if (!img || !win)
		return ;
	if (img->img)
		mlx_destroy_image(win->mlx_ptr, img->img);
	free(img);
}

void	destroy_tex(t_tex *tex, t_win *win)
{
	if (!tex || !win)
		return ;
	destroy_image (tex->north_tex, win);
	destroy_image (tex->south_tex, win);
	destroy_image (tex->east_tex, win);
	destroy_image (tex->west_tex, win);
	free (tex);
}
