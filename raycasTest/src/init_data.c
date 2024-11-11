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

// Fonction pour initialiser l'image
void	init_image(t_data *data, t_image *img, char *filename)
{
    img->img = mlx_xpm_file_to_image(data->mlx, filename, &img->width, &img->height);
    if (!img->img)
    {
        printf("Erreur de chargement de l'image: %s\n", filename);
        exit(1);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
}

// Fonction pour dessiner un pixel sur l'image
void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
    int pixel_index;

    if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
    {
        pixel_index = (y * img->line_length + x * (img->bpp / 8));
        *(unsigned int *)(img->addr + pixel_index) = color;
    }
}

// Fonction pour obtenir la couleur d'un pixel dans une texture
int	get_texture_pixel(t_image *img, int x, int y)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return 0; // Retourner noir si on sort des limites
    int pixel_index = (y * img->line_length + x * (img->bpp / 8));
    return *(unsigned int *)(img->addr + pixel_index);
}
