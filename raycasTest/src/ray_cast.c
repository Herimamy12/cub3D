/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:01:57 by nherimam          #+#    #+#             */
/*   Updated: 2024/11/11 22:02:00 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// Fonction de raycasting (calcul de la distance et projection)
void	cast_ray(t_data *data, double ray_angle, int column)
{
	int		hit = 0;

	int		map_x;
	int		map_y;

    int		line_height;
    int		line_start;
    int		line_end;

	int		texture_x;
	int		texture_y;
	int		color;

	double	ray_x = data->player.x;
	double	ray_y = data->player.y;
	double	ray_dx = cos(ray_angle);
	double	ray_dy = sin(ray_angle);

	double	distance = 0;
	double	corrected_distance;

    // Normaliser l'angle pour le rendre dans la plage [0, 2*PI]
    ray_angle = fmod(ray_angle, 2 * M_PI);
    if (ray_angle < 0)
    	ray_angle += 2 * M_PI;

    // Lancer le rayon jusqu'à rencontrer un mur
    while (!hit)
    {
        ray_x += ray_dx * 0.1;
        ray_y += ray_dy * 0.1;
        distance += 0.1;

        // Vérifier si on touche un mur
        map_x = (int)ray_x;
        map_y = (int)ray_y;
        if (map_y >= 0 && map_y < MAP_HEIGHT && map_x >= 0 && map_x < MAP_WIDTH)
        {
            if (map[map_y][map_x] == '1')
                hit = 1;
        }
    }

    // Correction du fish-eye : ajuster la distance en fonction de l'angle du rayon
    corrected_distance = distance * cos(ray_angle - data->player.angle);

    // Projeter l'image en fonction de la distance corrigée
    line_height = (int)(WIN_HEIGHT / corrected_distance);
    line_start = (WIN_HEIGHT - line_height) / 2;
    line_end = line_start + line_height;

    // Calculer le point sur la texture à afficher en fonction de la distance
    texture_x = (int)(ray_x * 64) % data->wall_tex.width;
    for (int y = line_start; y < line_end; y++)
    {
        texture_y = (int)((y - line_start) / (double)line_height * data->wall_tex.height);
        color = get_texture_pixel(&data->wall_tex, texture_x, texture_y);
        my_mlx_pixel_put(&data->win_tex, column, y, color);  // Utiliser `win_tex` pour afficher la scène
    }
}
