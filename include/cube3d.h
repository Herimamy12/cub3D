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
# define M_WIDTH 120
# define M_HEIGHT 80
# define MW_SIZE 8			// mini wall size
# define M_STARTW 10
# define M_STARTH 450		// (HEIGHT - M_HEIGHT - 10)

// FIELD OF VIEW PLAYER 90°
# define FOV 1.5708			// (M_PI / 2)

// CONST FOR THE ADDITION IN THE RAY CAST DIM
# define ADDCAST 0.005

// ROTATION SPEED
# define S_ROTATION 0.035
# define S_MOOVEMENT 2

// QUIT
# define ESC 65307

// ANGLE ORIENTATION FORT 3D
# define DEGEAS 0
# define DEGNOR 4.7124		// ((3 * M_PI) / 2)
# define DEGWES M_PI
# define DEGSOT 1.5708		// (M_PI / 2)

// LOCATION (DEPLACEMENT FLECHE)
# define NORTH 119
# define SOUTH 115
# define WEST 97
# define EAST 100

// ROTATION CAMERA (RC_)
# define RC_LEFT 65361
# define RC_RIGHT 65363

// COLOR
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define SKYBLUE 0x87CEEB
# define BLACK 0x00000000
# define BLACK_WALL 0x00000020
# define GREEN 0x0000FF00
# define GREENLAND 0x2E8B57
# define WHITE 0x00FFFFFF
# define YELLOW 0xFFFF00
# define GRAY 0x333333
# define RAY_GRAY 0x4F4F4F4F

// WINDOW STRUCT
typedef struct s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_win;

// MAP STRUCT
typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	char	*text_no;
	char	*text_so;
	char	*text_ea;
	char	*text_we;
}			t_map;

// TEXTURES IMAGES STRUCT
typedef struct s_image
{
	int		bpp;
	int		width;
	int		endian;
	int		line_length;
	int		height;
	char	*addr;
	void	*img;
}			t_image;

// PLAYER STRUCT FOR 3D
typedef struct s_cubplay
{
	int		l_r;
	int		u_d;
	double	width;
	double	height;
	double	angle;
}			t_cubplay;

// RAY REQUIREMENT STRUCT
typedef struct s_ray
{
	double	angle;
	double	width;
	double	height;
	double	dwidth;
	double	dheight;
	double	distance;
}			t_ray;

// STRUCT FOR THE WALL
typedef struct s_wall
{
	int	end;
	int	start;
	int	height;
	int	tex_w;
	int	tex_h;
}		t_wall;

// STRUCT FOR MINI MAP
typedef struct s_mini
{
	int		play_w;		// mini width player position
	int		play_h;
	int		offset_w;
	int		offset_h;
	double	angle;
	double	ray_w;
	double	ray_h;
	double	step_w;
	double	step_h;
}			t_mini;

// DATA STRUCT
typedef struct s_data
{
	t_ray		*ray;
	t_win		*win;
	t_map		*map;
	t_wall		*wall;
	t_mini		*mini;
	t_image		*win_tex;
	t_image		*wall_tex;
	t_image		*east_tex;
	t_image		*west_tex;
	t_image		*north_tex;
	t_image		*south_tex;
	t_cubplay	*cubplay;
}				t_data;

// NEW && DESTROY (DATA AND WINDOW)
t_win		*new_win(void);
t_data		*new_data(char *av);
void		destroy_str(char **str);
void		destroy_win(t_win *win);
void		destroy_data(t_data *data);
int			close_win(t_data *data);

// MAP && PARSING
t_map		*new_struct_map(char *av);
char		**new_map(char *av);
char		**get_map(int fd);
int			count_width_map(char **map);
int			count_heigth_map(char **map);
void		destroy_map(t_map *map);

// LOOP && MOOV && KEYPRESS
int			handle_keypress(int keycode, t_data *data);
int			handle_mouse_move(int x, int y, t_data *data);
void		loop_cub3d(t_data *data);

// OTHER && DEBUG
void		print_map(char **map);

// INITIATION OF 3D
t_cubplay	*new_cubplay(t_map *map);
double		get_angle(char **map, int width, int height);
t_image		*alloc_image(void);
t_image		*new_win_texture(t_data *data);
void		destroy_image(t_image *img, t_win *win);
int			is_player(char set);
void		adjust_ray_angle(t_data *data);
t_ray		*init_ray(void);
void		cast_ray_wall(t_data *data);
int			rotate_cub(float angle, t_data *data);
void		assign_the_wall(t_data *data, int width);
int			is_cub_event(int keycode);
int			cub_event(int keycode, t_data *data);
int			moovement(t_data *data, double w, double h);
void		reset_flag(t_data *data);
int			is_wall(t_data *data, double w, double h);
void		init_all_image(t_data *data);
void		get_wall_texture(t_data *data, int map_w, int map_h);
t_wall		*init_wall(void);
t_mini		*init_mini(void);

// INIT
void		init_image(t_data *data, t_image *img, char *filename);
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
int			get_texture_pixel(t_image *img, int x, int y);

// RAYCAST
void		cast_ray(t_data *data, int width);

// RENDER
void		render(t_data *data);

// MINI MAP
void		draw_mini_map(t_data *data);
void		draw_border(t_data *data);
void		draw_mini_ray(t_data *data);
void		draw_mini_wall(t_data *data);
void		draw_mini_player(t_data *data);
void		put_mini_wall(t_data *data, int width, int height);
void		put_mini_ray(t_data *data, double step_x, double step_y);

// PARSE MAP
int			is_line_map(char *line);
int			lft_strcmp(char *s1, char *s2);
int			is_arg_valid(char *av);
char		*get_texture(char **map, char *text);
int			is_line_map(char *line);
int			is_space_only(char *line);
int			is_surround(char *line);
int			cnt_player(char *line);
int			is_one_player(char **map, int x);
int			is_arg_valid(char *av);
int			count_path(char **map, char *str, int x);
int			verify_count(char **map, int x);
int			verify_elem(char **map, int x);
int			is_map_valid(char **map, int x);
int			is_in_order(char **map);
int			get_color(char	**map, char *color);

#endif
