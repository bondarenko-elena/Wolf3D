/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:36:16 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 11:05:41 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <time.h>

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define KEY_ESC 53

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define SWITCH_TEXTURES 17
# define SWITCH_MUSIC 46
# define MUTE 45

# define ROTATE_LEFT 12
# define ROTATE_RIGHT 14

# define R 0.1
# define M 1.5708
# define C 0.05

typedef struct		s_ray
{
	int				**map;
	int				map_width;
	int				map_height;
	int				map_x;
	int				map_y;
	double			camera;
	int				hit;
	int				side_of_the_world;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			old_dir_x;
	double			plane_x;
	double			plane_y;
	double			old_plane_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_d;
	int				step_x;
	int				step_y;
	int				line_height;
	int				start;
	int				end;
	unsigned int	color;
	int				d;
	int				switch_textures;
	double			wall;
	int				tex_x;
	int				tex_y;
	int				fl_tex_x;
	int				fl_tex_y;
	int				music_tumbler;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx_init;
	void			*window;
	void			*image;
	int				*adress;
	int				endian;
	int				size_line;
	int				bits_per_pixel;
}					t_mlx;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_env
{
	t_mlx			*mlx;
	t_ray			*ray;
	t_color			*color;
	void			*img[4];
	char			*data[4];
	int				endian[4];
	int				size_line[4];
	int				bits_per_pixel[4];
	int				fd;
	int				up;
	int				down;
	int				left;
	int				right;
	int				rot_right;
	int				rot_left;
	int				check_chars;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
}					t_env;

unsigned int		add_smog(unsigned int c, double d);
void				calculate_distance(t_env *env);
void				calculate_step_side(t_env *env);
int					check_file(t_env *env);
int					check_line(char *str);
int					check_map(t_env *env);
int					check_map2(int length, char **str_splitted, char *str);
int					check_walls_exist(t_ray *ray);
void				default_wall(t_env *env, int x);
void				define_color1(t_env *env, int def, int iterator);
void				define_color2(t_env *env, int def, int iterator);
void				ray_init(t_env *env, int x);
void				display_text(t_env *env);
void				do_magic(t_env *env);
void				draw(t_env *env, int x);
void				free_struct(t_env *env);
void				free_tab_char(char **tab);
void				free_tab_int(int **tab, int map_h);
int					get_color_tex(t_env *env, int y, int t);
void				get_data_addr(t_env *env);
t_env				*init_env(t_env *env);
void				init_map_size(t_env *env, int h);
void				init_textures(t_env *env);
void				init_window(t_env *env);
int					key_press(int keycode, t_env *env);
void				key_press_init(int keycode, t_env *env);
int					key_release(int keycode, t_env *env);
int					main(int argc, char **argv);
void				malloc_error(void);
void				map_error(void);
void				move_down(t_env *env);
void				move_left(t_env *env);
void				move_right(t_env *env);
void				move_up(t_env *env);
int					moves(t_env *env);
int					open_file(t_env *env, char *filename);
void				play_music();
void				print_keycode(int keycode);
void				ray_casting(t_env *env);
void				ray_init(t_env *env, int x);
int					read_error(void);
void				read_file(t_env *envs, char *filename);
void				read_map(t_env *env);
int					red_cross(t_env *env);
void				redraw(t_env *env);
void				rotate_left(t_env *env);
void				rotate_right(t_env *env);
void				textured_wall(t_env *env, int x);

#endif
