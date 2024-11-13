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

# include <math.h>
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

// ONE BLOC FIXE && PLAYER FIXE 2D
# define CUB_BWIDTH 60
# define CUB_BHEIGHT 60
# define CUB_PWIDTH 30
# define CUB_PHEIGHT 30

// FIELD OF VIEW PLAYER 90°
# define FOV 1.5708			// (M_PI / 2)

// CONST FOR THE ADDITION IN THE RAY CAST DIM
# define ADDCAST 0.005

// ROTATION SPEED
# define S_ROTATION 0.035
# define S_MOVEMENT 2

// QUIT
# define ESC 65307

// DEGRE ORIENTATION BASE EST FOR 2D
# define DEGERR -1
# define DEGEA 0
# define DEGNO 90
# define DEGWE 180
# define DEGSO 270
# define DEGMAX 360
# define DEGMIN 0

// ANGLE ORIENTATION FORT 3D
# define DEGEAS 0
# define DEGNOR 4.7124		// ((3 * M_PI) / 2)
# define DEGWES M_PI
# define DEGSOT 1.5708		// (M_PI / 2)

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
# define SKYBLUE 0x87CEEB
# define BLACK 0x00000000
# define GREEN 0x0000FF00
# define GREENLAND 0x2E8B57
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

// TEXTURES IMAGES STRUCT
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

// FORBIDDDEN GROUND STRUCT
typedef struct s_forb
{
	int				width;
	int				height;
	struct s_forb	*next;
}					t_forb;

// PLAYER STRUCT FOR 2D
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

// PLAYER STRUCT FOR 3D
typedef struct s_cubplay
{
	double	width;
	double	height;
	double	angle;
	int		l_r;
	int		u_d;
}			t_cubplay;

typedef struct s_ray
{
	double	angle;
	double	width;
	double	height;
	double	dwidth;
	double	dheight;
	double	distance;
}			t_ray;

// DATA STRUCT
typedef struct s_data
{
	t_ray		*ray;
	t_win		*win;
	t_map		*map;
	t_forb		*forb;		// just for 2d forbidden ground
	t_scale		*dim;		// 2d dimension calc
	t_player	*player;	// for player 2d
	t_cubplay	*cubplay;
	t_image		*win_tex;
	t_image		*wall_tex;
	t_image		*east_tex;
	t_image		*west_tex;
	t_image		*north_tex;
	t_image		*south_tex;
	int			texture_x;	// pour les coordonnées des textures
	int			texture_y;
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

// INITIATION OF 3D
t_cubplay	*new_cubplay(t_map *map);
double		get_angle(char **map, int width, int height);
t_image		*alloc_image(void);
t_image		*new_win_texture(t_data *data);
void		destroy_image(t_image *img, t_win *win);
int			is_player(char set);
double		adjust_ray_angle(double ray_angle);
t_ray		*init_ray(void);
void		cast_ray_wall(t_data *data);
void		put_the_wall(t_data *data, int start, int end, int width);
int			rotate_cub(int keycode, t_data *data);
int			is_cub_event(int keycode);
int			cub_event(int keycode, t_data *data);
int			movement(t_data *data, double w, double h);
void		reset_flag(t_data *data);
int			is_wall(t_data *data, double w, double h);
void		init_all_image(t_data *data);
void		get_wall_texture(t_data *data, int map_w, int map_h);

// BEGIN CHAT
// INIT
void		init_image(t_data *data, t_image *img, char *filename);
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
int			get_texture_pixel(t_image *img, int x, int y);

// RAYCAST
void		cast_ray(t_data *data, double ray_angle, int column);

// RENDER
void		render(t_data *data);
// END CHAT

#endif
