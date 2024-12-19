/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:05:50 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/19 13:05:51 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	destroy_load(t_load *load)
{
	if (!load)
		return ;
	destroy_image (load->win_tex, load->win);
	destroy_anim (load->anim, load->win);
	destroy_win (load->win);
	free (load);
	exit (0);
}
