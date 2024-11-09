/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbidden_ground.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:57:30 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/04 20:57:34 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_forb	*new_forb(int width, int height)
{
	t_forb	*new;

	new = (t_forb *)malloc(sizeof(t_forb));
	if (!new)
		return (NULL);
	new->width = width;
	new->height = height;
	new->next = NULL;
	return (new);
}

void	forb_addback(t_forb **forb, t_forb *next)
{
	t_forb	*tmp;

	tmp = forb[0];
	while (forb[0] && forb[0]->next)
		forb[0] = forb[0]->next;
	forb[0]->next = next;
	forb[0] = tmp;
}
