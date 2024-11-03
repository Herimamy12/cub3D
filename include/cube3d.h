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
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

// WINDOW PARAMETER
# define WIDTH 960
# define HEIGHT 540
# define NAME "cube3d"

// QUIT
# define ESC 65307

// // DIRECTION CLIC
// # define F_UP 65362
// # define F_DOWN 65364
// # define F_LEFT 65361
// # define F_RIGHT 65363

// LOCATION
# define NORTH 65362
# define SOUTH 65364
# define WEST 65361
# define EAST 65363

// COLOR
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define WHITE 0x00FFFFFF

// WINDOW STRUCT
typedef struct s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_win;

// SIZE : wb : width_brick and wp : width_player
typedef struct s_size
{
	int	wb;
	int	hb;
	int	wp;
	int	hp;
}		t_size;

// PLAYER STRUCT
typedef struct s_player
{
	int	posi;
	int	old_posi;
	int	posj;
	int	old_posj;
}		t_player;

// DATA STRUCT
typedef struct s_data
{
	char		**map;
	t_win		*win;
	t_size		*dim;
	t_player	*player;
}				t_data;

// NEW && DESTROY (DATA AND WINDOW)
t_win		*new_win(void);
t_data		*new_data(char *av);
t_player	*new_player(void);
void		destroy_str(char **str);
void		destroy_win(t_win *win);
void		destroy_data(t_data *data);
int			close_win(t_data *data);

// MAP && PARSING
char		**new_map(char *av);
char		**get_map(int fd);

// LOOP && MOOV && KEYPRESS
int			handle_keypress(int keycode, t_data *data);
void		put_player(t_win *win, t_player *player);
void		loop_cub3d(t_data *data);
void		remove_old_player(t_win *win, t_player *player);
int			ft_mov_player(int keycode, t_player *player);

// OTHER && DEBUG
void		print_map(char **map);

#endif
