/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:14:41 by nherimam          #+#    #+#             */
/*   Updated: 2024/10/03 23:14:43 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define WIN_WIDTH 960
# define WIN_HEIGHT 540
// # define FOV 60.0 // Champ de vision de 60°
# define FOV (M_PI / 2) // Champ de vision de 60°

# define MAP_WIDTH 7
# define MAP_HEIGHT 7

// Structures pour gérer l'image
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle; // Direction de vue du joueur
}			t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_image		win_tex;		// Image pour le rendu de la fenêtre
	t_image		wall_tex;		// Texture des murs
	t_image		floor_tex;		// Texture du sol
	t_image		ceiling_tex;	// Texture du plafond
}				t_data;

#endif
