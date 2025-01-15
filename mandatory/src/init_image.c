/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:53:25 by nherimam          #+#    #+#             */
/*   Updated: 2024/12/29 17:53:27 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_all_image(t_data *data)
{
	init_image(data, data->tex->east_tex, data->map->text_ea);
	init_image(data, data->tex->west_tex, data->map->text_we);
	init_image(data, data->tex->north_tex, data->map->text_no);
	init_image(data, data->tex->south_tex, data->map->text_so);
}

t_tex	*init_tex(void)
{
	t_tex	*tex;

	tex = (t_tex *)malloc(sizeof(t_tex));
	if (!tex)
		return (NULL);
	tex->east_tex = alloc_image();
	tex->west_tex = alloc_image();
	tex->north_tex = alloc_image();
	tex->south_tex = alloc_image();
	return (tex);
}
