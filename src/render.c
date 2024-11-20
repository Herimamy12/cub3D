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

/* ************************************************************************** */

# define WALL_COLOR 0x000000  // Noir pour les murs
# define PLAYER_COLOR 0xFF0000  // Rouge pour le joueur
# define PLAYER_DIRECTION_COLOR 0x00FF00  // Vert pour la direction du joueur

void	draw_mini_map(t_data *data);
void	draw_player_direction(t_data *data, int x, int y, int scale);
void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color);

/* ************************************************************************** */

void	render(t_data *data)
{
	int		width;
	int		height;

	height = -1;
	while (++height < HEIGHT / 2)
	{
		width = -1;
		while (++width < WIDTH)
		{
			my_mlx_pixel_put(data->win_tex, width, height, SKYBLUE);
			my_mlx_pixel_put(data->win_tex,
				width, HEIGHT - height - 1, GREENLAND);
		}
	}
	width = -1;
	while (++width < WIDTH)
	{
		data->ray->angle = data->cubplay->angle - FOV / 2.0
			+ (width / (double)WIDTH) * FOV;
		adjust_ray_angle(data);
		cast_ray(data, width);
	}
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->mlx_win,
		data->win_tex->img, 0, 0);
	draw_mini_map(data);
}

void	adjust_ray_angle(t_data *data)
{
	data->ray->angle = fmod(data->ray->angle, 2 * M_PI);
	if (data->ray->angle < 0)
		data->ray->angle += 2 * M_PI;
}

/* *************************************************************** */

void draw_mini_map(t_data *data)
{
    int map_x, map_y;
    int mini_map_size = 150;  // Taille de la mini-map en pixels
    int map_scale = mini_map_size / data->map->width;  // Facteur de mise à l'échelle
    int player_x, player_y;
    
    // Définir la position de la mini-map (en bas à gauche)
    int mini_map_x = 10;
    int mini_map_y = HEIGHT - mini_map_size - 10;
    
    // Afficher les murs de la carte dans la mini-map
    for (map_y = 0; map_y < data->map->height; map_y++)
    {
        for (map_x = 0; map_x < data->map->width; map_x++)
        {
            if (data->map->map[map_y][map_x] == '1')  // Si c'est un mur
            {
                // Calculer la position à afficher dans la mini-map
                my_mlx_pixel_put(data->win_tex, 
                    mini_map_x + map_x * map_scale, 
                    mini_map_y + map_y * map_scale, 
                    WALL_COLOR);  // Utiliser la couleur du mur
            }
        }
    }

    // Afficher la position du joueur dans la mini-map
    player_x = (int)(data->cubplay->width * map_scale);
    player_y = (int)(data->cubplay->height * map_scale);
    
    // Marquer la position du joueur avec un pixel distinct (par exemple, rouge)
    my_mlx_pixel_put(data->win_tex, 
        mini_map_x + player_x, 
        mini_map_y + player_y, 
        PLAYER_COLOR);  // Utiliser une couleur distinctive pour le joueur

    // Afficher la direction du joueur sur la mini-map (optionnel)
    draw_player_direction(data, mini_map_x + player_x, mini_map_y + player_y, map_scale);
}

// Fonction pour dessiner la direction du joueur sur la mini-map
void draw_player_direction(t_data *data, int x, int y, int scale)
{
    int line_length = 10;  // Longueur de la flèche indiquant la direction
    double angle = data->cubplay->angle;  // L'angle du joueur

    int end_x = x + (int)(cos(angle) * line_length * scale);
    int end_y = y + (int)(sin(angle) * line_length * scale);

    // Dessiner une ligne représentant la direction du joueur
    draw_line(data, x, y, end_x, end_y, PLAYER_DIRECTION_COLOR);
}

// Fonction pour dessiner une ligne (nécessaire pour afficher la direction du joueur)
void draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    
    while (1)
    {
        my_mlx_pixel_put(data->win_tex, x1, y1, color);
        
        if (x1 == x2 && y1 == y2)
            break;
        
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

