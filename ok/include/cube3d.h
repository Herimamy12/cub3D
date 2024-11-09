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

// ONE BLOC FIXE && PLAYER FIXE
# define CUB_BWIDTH 60
# define CUB_BHEIGHT 60
# define CUB_PWIDTH 30
# define CUB_PHEIGHT 30

// QUIT
# define ESC 65307

// DEGRE ORIENTATION BASE EST
# define DEGERR -1
# define DEGEA 0
# define DEGNO 90
# define DEGWE 180
# define DEGSO 270
# define DEGMAX 360
# define DEGMIN 0

// LOCATION (DEPLACEMENT FLECHE)
# define NORTH 65362
# define SOUTH 65364
# define WEST 65361
# define EAST 65363

// ROTATION CAMERA (RC_)
# define RC_LEFT 65430 // touche pad 4
# define RC_RIGHT 65432 // touche pad 6

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

// SIZE (Only for 2D)
typedef struct s_scale
{
	int	wb;		// wb : width_brick in scale variable
	int	hb;
	int	wp;		// wp : width_player
	int	hp;
}		t_scale;

// MAP STRUCT
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}			t_map;

// FORBIDDDEN GROUND STRUCT
typedef struct s_forb
{
	int				width;
	int				height;
	struct s_forb	*next;
}					t_forb;

// PLAYER STRUCT
typedef struct s_player
{
	int	mapw;	// position in the map 2D
	int	maph;
	int	posw;	// position width player en pixel
	int	old_posw;
	int	posh;
	int	old_posh;
	int	orientation;
	int	old_orientation;
}		t_player;

// DATA STRUCT
typedef struct s_data
{
	t_win		*win;
	t_map		*map;
	t_forb		*forb;
	t_scale		*dim;
	t_player	*player;
}				t_data;

// NEW && DESTROY (DATA AND WINDOW)
t_win		*new_win(void);
t_data		*new_data(char *av);
t_player	*new_player(t_map *map, t_scale *dim);
t_scale		*init_dimension(t_map *map);
void		destroy_str(char **str);
void		destroy_win(t_win *win);
void		destroy_data(t_data *data);
int			close_win(t_data *data);

// ALL FORBIDEN GROUND
t_forb		*new_forb(int width, int height);
void		forb_addback(t_forb **forb, t_forb *next);
void		destroy_list(t_forb *forb);

// MAP && PARSING
t_map		*new_struct_map(char *av);
char		**new_map(char *av);
char		**get_map(int fd);
int			count_width_map(char **map);
int			count_heigth_map(char **map);
void		destroy_map(t_map *map);

// LOOP && MOOV && KEYPRESS
int			handle_keypress(int keycode, t_data *data);
void		put_player(t_win *win, t_player *player);
void		loop_cub3d(t_data *data);
void		remove_old_player(t_win *win, t_player *player);
int			ft_mov_player(int keycode, t_data *data);
void		let_mov_north(t_data *data, t_forb *forb, t_forb *tmp);
void		let_mov_south(t_data *data, t_forb *forb, t_forb *tmp);
void		let_mov_east(t_data *data, t_forb *forb, t_forb *tmp);
void		let_mov_west(t_data *data, t_forb *forb, t_forb *tmp);

// LOOP && BRICK WALL 2D && PLAYER 2D
void		fill_screen2d(t_data *data);
void		fill_brick_wall2d(t_data *data, int height, int width);
int			get_height_position(t_map *map);
int			get_width_position(t_map *map);
int			get_player_orientation(t_map *map);
void		put_orientation_east(t_win *win, t_player *player);
void		put_orientation_north(t_win *win, t_player *player);
void		put_orientation_south(t_win *win, t_player *player);
void		put_orientation_west(t_win *win, t_player *player);
void		maj_data_player(t_player *player);
void		put_player_orientation(t_win *win, t_player *player);
void		removed_player_orientation(t_win *win, t_player *player);
void		removed_orientation_east(t_win *win, t_player *player);
void		removed_orientation_north(t_win *win, t_player *player);
void		removed_orientation_south(t_win *win, t_player *player);
void		removed_orientation_west(t_win *win, t_player *player);
void		let_rotate_left(t_player *player);
void		let_rotate_right(t_player *player);

// OTHER && DEBUG
void		print_map(char **map);
void		print_one_forb(t_forb *forb);
void		print_list_forb(t_forb *forb);

#endif
