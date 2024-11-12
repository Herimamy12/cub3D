/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:56:41 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/11 21:56:44 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_image(t_data *data, t_image *img, char *filename)
{
	img->img = mlx_xpm_file_to_image(data->win->mlx_ptr, filename,
			&img->width, &img->height);
	if (!img->img)
	{
		printf("Erreur de chargement de l'image: %s\n", filename);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	int	pixel_index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_index = (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)(img->addr + pixel_index) = color;
	}
}

int	get_texture_pixel(t_image *img, int x, int y)
{
	int	pixel_index;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	pixel_index = (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)(img->addr + pixel_index));
}

t_image	*new_win_texture(t_data *data)
{
	t_image	*win_tex;

	win_tex = (t_image *)malloc(sizeof(t_image));
	if (!win_tex)
		return (NULL);
	win_tex->img = mlx_new_image(data->win->mlx_ptr, WIDTH, HEIGHT);
	win_tex->bpp = 0;
	win_tex->line_length = 0;
	win_tex->endian = 0;
	win_tex->addr = mlx_get_data_addr(win_tex->img, &win_tex->bpp,
			&win_tex->line_length, &win_tex->endian);
	return (win_tex);
}

t_ray	*init_ray(void)
{
	t_ray	*new;

	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->angle = 0;
	new->width = 0;
	new->height = 0;
	new->dwidth = 0;
	new->dheight = 0;
	new->distance = 0;
	return (new);
}
