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

void	draw_mini_map(t_data *data);
void	draw_border(t_data *data);

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

/* *************************************************************** */

void draw_mini_map(t_data *data)
{
	draw_border(data);
	// draw_mini_wall(data);

    // Calcul des décalages pour centrer le joueur
    int offset_x = (int)data->cubplay->width - M_WIDTH / (2 * MW_SIZE);
    int offset_y = (int)data->cubplay->height - M_HEIGHT / (2 * MW_SIZE);

    // Parcours des murs à afficher
    for (int y = 0; y < M_HEIGHT / MW_SIZE; y++)
    {
        for (int x = 0; x < M_WIDTH / MW_SIZE; x++)
        {
            int map_x = x + offset_x;
            int map_y = y + offset_y;

            if (map_y >= 0 && map_y < data->map->height && map_x >= 0 && map_x < data->map->width)
            {
                if (data->map->map[map_y][map_x] == '1') // Mur
                {
                    for (int dy = 0; dy < MW_SIZE - 1; dy++)
                    {
                        for (int dx = 0; dx < MW_SIZE - 1; dx++)
                        {
                            my_mlx_pixel_put(data->win_tex, 
                                M_STARTW + x * MW_SIZE + dx, 
                                M_STARTH + y * MW_SIZE + dy, 
                                0x00000020);
                        }
                    }
                }
            }
        }
    }

    // Affichage des rayons
    for (int i = 0; i < WIDTH; i += 10) // Espacement des rayons pour performance
    {
        double ray_angle = data->cubplay->angle - FOV / 2.0 + (i / (double)WIDTH) * FOV;
        double ray_x = data->cubplay->width;
        double ray_y = data->cubplay->height;
        double step_x = cos(ray_angle);
        double step_y = sin(ray_angle);

        while (1)
        {
            int map_x = (int)ray_x;
            int map_y = (int)ray_y;
            if (map_x < 0 || map_y < 0 || map_x >= data->map->width || map_y >= data->map->height || data->map->map[map_y][map_x] == '1')
                break;

            int pixel_x = M_STARTW + (ray_x - offset_x) * MW_SIZE;
            int pixel_y = M_STARTH + (ray_y - offset_y) * MW_SIZE;

            if (pixel_x < M_STARTW || pixel_x >= M_STARTW + M_WIDTH || pixel_y < M_STARTH || pixel_y >= M_STARTH + M_HEIGHT)
                break;

            my_mlx_pixel_put(data->win_tex, pixel_x, pixel_y, RAY_GRAY);

            ray_x += step_x * 0.2;
            ray_y += step_y * 0.2;
        }
    }

    // Calcul de la position du joueur sur la mini-carte
	int player_pixel_x = M_STARTW + (data->cubplay->width - offset_x) * MW_SIZE;
	int player_pixel_y = M_STARTH + (data->cubplay->height - offset_y) * MW_SIZE;

	// Affichage du joueur comme un point rouge
	player_pixel_y--;
	for (int i = 0; i < 3; i++)
	{
		player_pixel_x = (M_STARTW + (data->cubplay->width - offset_x) * MW_SIZE) - 1;
		for (int j = 0; j < 3; j++)
		{
			my_mlx_pixel_put(data->win_tex, player_pixel_x, player_pixel_y, RED);
			player_pixel_x++;
		}
		player_pixel_y++;
	}
}

void	draw_border(t_data *data)
{
	int	width;
	int	height;
	int	pixelw;
	int	pixelh;

	height = -2;
	while (++height <= M_HEIGHT)
	{
		width = -2;
		while (++width <= M_WIDTH)
		{
			pixelw = M_STARTW + width;
			pixelh = M_STARTH + height;
			if (height == -1 || width == -1 || height == M_HEIGHT || width == M_WIDTH)
				my_mlx_pixel_put(data->win_tex, pixelw, pixelh, WHITE);
			else
				my_mlx_pixel_put(data->win_tex, pixelw, pixelh, GRAY);
		}
	}
}
