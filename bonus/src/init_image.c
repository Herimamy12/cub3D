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
	init_image(data, data->tex->door_tex, "./bonus/textures/door.xpm");
	init_image(data, data->tex->close_tex, "./bonus/textures/close.xpm");
	init_anim_image(data);
	init_door_image(data);
}

void	init_door_image(t_data *data)
{
	init_image(data, data->door->zero, "./bonus/textures/door/0.xpm");
	init_image(data, data->door->one, "./bonus/textures/door/1.xpm");
	init_image(data, data->door->two, "./bonus/textures/door/2.xpm");
	init_image(data, data->door->three, "./bonus/textures/door/3.xpm");
	init_image(data, data->door->four, "./bonus/textures/door/4.xpm");
	init_image(data, data->door->five, "./bonus/textures/door/5.xpm");
	init_image(data, data->door->six, "./bonus/textures/door/6.xpm");
	init_image(data, data->door->seven, "./bonus/textures/door/7.xpm");
	init_image(data, data->door->eight, "./bonus/textures/door/8.xpm");
}

void	init_anim_image(t_data *data)
{
	init_image(data, data->anim->zero, "./bonus/textures/anime/0.xpm");
	init_image(data, data->anim->one, "./bonus/textures/anime/1.xpm");
	init_image(data, data->anim->two, "./bonus/textures/anime/2.xpm");
	init_image(data, data->anim->three, "./bonus/textures/anime/3.xpm");
	init_image(data, data->anim->four, "./bonus/textures/anime/4.xpm");
	init_image(data, data->anim->five, "./bonus/textures/anime/5.xpm");
	init_image(data, data->anim->six, "./bonus/textures/anime/6.xpm");
	init_image(data, data->anim->seven, "./bonus/textures/anime/7.xpm");
	init_image(data, data->anim->eight, "./bonus/textures/anime/8.xpm");
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
	tex->close_tex = alloc_image();
	tex->door_tex = alloc_image();
	return (tex);
}

t_anim	*init_anim(void)
{
	t_anim	*anim;

	anim = (t_anim *)malloc(sizeof(t_anim));
	if (!anim)
		return (NULL);
	anim->zero = alloc_image();
	anim->one = alloc_image();
	anim->two = alloc_image();
	anim->three = alloc_image();
	anim->four = alloc_image();
	anim->five = alloc_image();
	anim->six = alloc_image();
	anim->seven = alloc_image();
	anim->eight = alloc_image();
	return (anim);
}
