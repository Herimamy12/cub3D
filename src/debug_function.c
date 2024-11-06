/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:43:48 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/05 23:43:49 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

void	print_one_forb(t_forb *forb)
{
	if (!forb)
		return ;
	printf("width : %d | height : %d\n", forb->width, forb->height);
}

void	print_list_forb(t_forb *forb)
{
	while (forb && forb->next)
	{
		print_one_forb(forb);
		forb = forb->next;
	}
	print_one_forb(forb);
}
