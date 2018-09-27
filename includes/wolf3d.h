#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <time.h>

// size of screen
# define WIDTH 1024
# define HEIGHT 768

// ESC: for MAC OS keycode == 53; for Debian keycode == 65307
# define KEY_ESC 65307
// W: for MAC OS keycode == 13; for Debian keycode == 119
# define KEY_UP 119
// S: for MAC OS keycode == 1; for Debian keycode == 115
# define KEY_DOWN 115
// A: for MAC OS keycode == 0; for Debian keycode == 97
# define KEY_LEFT 97
// D: for MAC OS keycode == 2; for Debian keycode == 100
# define KEY_RIGHT 100
// SPACE: for MAC OS keycode == 49; for Debian keycode == 32
# define KEY_JUMP 32
// UP: for MAC OS keycode == 126; for Debian keycode == 65362
# define ARROW_UP 65362
// DOWN: for MAC OS keycode == 125; for Debian keycode == 65364
# define ARROW_DOWN 65364
// LEFT: for MAC OS keycode == 123; for Debian keycode == 65361
# define ARROW_LEFT 65361
// RIGHT: for MAC OS keycode == 124; for Debian keycode == 65363
# define ARROW_RIGHT 65363
// M: for MAC OS keycode == 46; for Debian keycode == 109
# define SWITCH_MUSIC 109
// N: for MAC OS keycode == 45; for Debian keycode == 110
# define MUTE 110
// N: for MAC OS keycode == 17; for Debian keycode == 116
# define SWITCH_TEXTURES 116
// R: for MAC OS keycode == 15; for Debian keycode == 114
# define RESET_TEXTURES 114
// 1 - 7 to set certain texture
# define ONE 18
# define ONE_NUMPAD 83
# define TWO 19
# define TWO_NUMPAD 84
# define THREE 20
# define THREE_NUMPAD 85
# define FOUR 21
# define FOUR_NUMPAD 86
# define FIVE 23
# define FIVE_NUMPAD 87
# define SIX 22
# define SIX_NUMPAD 88
# define SEVEN 26
# define SEVEN_NUMPAD 89

// for int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
// x_mask is ignored on macos
# define KEY_PRESS_MASK (1L<<0)
// x_event set as 2 and funct set as an int key_press(int keycode, void *param) for a key press
# define KEY_PRESS 2

typedef struct		s_i_xy
{
	int				x;
	int				y;
}					t_i_xy;

typedef struct		s_dir_xy
{
	double			x;
	double			y;
}					t_dir_xy;

typedef struct		s_player
{
	struct s_dir_xy	position;
	struct s_dir_xy	direction;
	struct s_dir_xy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			is_jump;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			move_jump;
}					t_player;

typedef struct		s_ray
{
	struct s_dir_xy	position;
	struct s_dir_xy	direction;
	struct s_i_xy	map;
	struct s_dir_xy	side;
	struct s_dir_xy	delta;
	struct s_i_xy	step;
	double			distance;
	double			camera;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx_init;
	void			*window;
	void			*image;
	char			*pixel;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	clock_t			last_frame;
	clock_t			next_frame;
}					t_mlx;

typedef struct		s_env
{
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	unsigned int	color_ground;
	// int				start_x;
	// int				start_y;
	int 			switch_textures;
}					t_env;

unsigned int	add_smog(unsigned int c, double d);
int 			check_file(char *filename);
void			draw_line(t_env *e, int x, int start, int end);
void			display_text(t_env *env);
void			event(t_env *env);
void			get_position(int fd, t_env *e);
unsigned int	get_color(t_env *env);
t_env			*init_env(void);
void			init_player(t_env *env);
int				key_hook(int k, t_env *e);
int				loop_hook(t_env *env);
int				main(int argc, char **argv);
void			map_error(void);
void			malloc_error(void);
void			move_left(t_env *e);
void			move_right(t_env *e);
void			move_up(t_env *e);
void			move_down(t_env *e);
void			move_jump(t_env *e);
int				open_file(t_env *e, char *filename);
void			put_pixel(t_env *env, int x, int y, unsigned int c);
void 			play_music();
int				read_file(int fd, t_env *e);
void			read_line(char *line, int y, int **map, t_env *e);
void			ray_casting(t_env *env);
void			ray_draw(t_env *env, int x);
void			ray_calculate_distance(t_env *env);
void			ray_calculate_step_side(t_env *env);
void			ray_init(t_env *env, int x);
void 			switch_moves(int keycode, t_env *env);
void			switch_music(int keycode);
int 			switch_textures(int keycode);

#endif
