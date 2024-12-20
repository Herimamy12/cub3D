/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:13:56 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/03 23:13:58 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	draw_loading(t_load *load)
{
	int	w = 0, h = 0, width = -1, heigth = -1, color;

	while (++width < WIDTH)
	{
		heigth = -1;
		w = (int)(width * load->img->width) % WIDTH;
		while (++heigth < HEIGHT)
		{
			h = (int)(heigth * load->img->height) % HEIGHT;
			color = get_texture_pixel(load->img, w, h);
			my_mlx_pixel_put(load->win_tex, width, heigth, color);
		}
	}
}

int	render_loading(t_load *load)
{
	// mlx_put_image_to_window(load->win->mlx_ptr, load->win->mlx_win,
	// 	load->img->img,0, 0);
	draw_loading(load);
	mlx_put_image_to_window (load->win->mlx_ptr, load->win->mlx_win,
		load->win_tex->img, 0, 0);
	return (0);
}

void	loop_loading(t_load *load)
{
	// mlx_loop_hook (load->win->mlx_ptr, render_loading, load);
	render_loading(load);
}

int	main(int ac, char **av)
{
	int		flag;
	t_win	*win;
	t_load	*load;
	t_data	*data;

	if (ac != 2)
		return (write(2, "Error : argument\n", 17), 1);
	flag = 0;
	win = new_win();
	load = new_load (win, &flag);
	if (!load)
		return (write (2, "Error loading game\n", 19), 1);
	loop_loading (load);
	data = new_data (av[1], win, &flag);
	if (!data)
		return (write(2, "Error : creation data\n", 12), 1);
	get_color(data->map->map, "F");
	loop_cub3d (data);
	return (0);
}
