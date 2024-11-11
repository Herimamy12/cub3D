/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:03:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/11 22:03:42 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// Fonction pour gérer l'affichage global
void	render(t_data *data)
{
	double ray_angle;

    // Remplir l'écran avec le plafond et le sol
    for (int y = 0; y < WIN_HEIGHT / 2; y++)
    {
        for (int x = 0; x < WIN_WIDTH; x++)
        {
            my_mlx_pixel_put(&data->win_tex, x, y, 0x87CEEB); // Plafond bleu clair
            my_mlx_pixel_put(&data->win_tex, x, WIN_HEIGHT - y - 1, 0x2E8B57); // Sol vert
        }
    }

    // Lancer le raycasting pour chaque colonne
    for (int column = 0; column < WIN_WIDTH; column++)
    {
        ray_angle = data->player.angle - FOV / 2.0 + (column / (double)WIN_WIDTH) * FOV;
        cast_ray(data, ray_angle, column);
    }

    // Afficher l'image de la scène dans la fenêtre
    mlx_put_image_to_window(data->mlx, data->win, data->win_tex.img, 0, 0);
}
