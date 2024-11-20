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
# define FOV_COLOR 0xFFFF00  // Jaune pour le champ de vision

void	draw_mini_map(t_data *data);
void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color);
void    draw_fov(t_data *data, int x, int y, int scale);

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
	draw_mini_map(data);
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->mlx_win,
		data->win_tex->img, 0, 0);
}

void	adjust_ray_angle(t_data *data)
{
	data->ray->angle = fmod(data->ray->angle, 2 * M_PI);
	if (data->ray->angle < 0)
		data->ray->angle += 2 * M_PI;
}

/* ************************************************************************** */

void draw_mini_map(t_data *data)
{
    int map_x, map_y;
    int mini_map_size = 120;
    int map_scale = mini_map_size / 20;
    int wall_scale = 5;  // Taille fixe de 5x5 pour chaque mur
    int player_x, player_y;
    
    int mini_map_x = 15;
    int mini_map_y = HEIGHT - 120;
    
    // Limite de la zone à afficher autour du joueur
    int view_distance = 8;  // Nombre de cases autour du joueur à afficher
    
    // Calculer la zone à afficher autour du joueur
    int player_map_x = (int)(data->cubplay->width);
    int player_map_y = (int)(data->cubplay->height);
    
    int start_x = player_map_x - view_distance;
    int start_y = player_map_y - view_distance;
    int end_x = player_map_x + view_distance;
    int end_y = player_map_y + view_distance;

    // Limiter les coordonnées aux bords de la carte
    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;
    if (end_x >= data->map->width) end_x = data->map->width - 1;
    if (end_y >= data->map->height) end_y = data->map->height - 1;

    for (map_y = start_y; map_y <= end_y; map_y++)
    {
        for (map_x = start_x; map_x <= end_x; map_x++)
        {
            if (data->map->map[map_y][map_x] == '1')  // Si c'est un mur
            {
                for (int i = 0; i < wall_scale; i++)
                {
                    for (int j = 0; j < wall_scale; j++)
                    {
                        my_mlx_pixel_put(data->win_tex, 
                            mini_map_x + (map_x - start_x) * map_scale + i, 
                            mini_map_y + (map_y - start_y) * map_scale + j, 
                            WALL_COLOR);
                    }
                }
            }
        }
    }

    player_x = (int)((data->cubplay->width - start_x) * map_scale);
    player_y = (int)((data->cubplay->height - start_y) * map_scale);
    
    my_mlx_pixel_put(data->win_tex, 
        mini_map_x + player_x, 
        mini_map_y + player_y, 
        PLAYER_COLOR);

    draw_fov(data, mini_map_x + player_x, mini_map_y + player_y, map_scale);
}


void draw_fov(t_data *data, int x, int y, int scale)
{
    double fov_angle = FOV;
    double player_angle = data->cubplay->angle;
    int fov_distance = 10;
    int num_rays = 20;

    double left_angle = player_angle - (fov_angle / 2);

    for (int i = 0; i < num_rays; i++)
    {
        double current_angle = left_angle + (i * fov_angle / (num_rays - 1));

        int end_x = x + (int)(cos(current_angle) * fov_distance * scale);
        int end_y = y + (int)(sin(current_angle) * fov_distance * scale);

        draw_line(data, x, y, end_x, end_y, FOV_COLOR);
    }
}


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
