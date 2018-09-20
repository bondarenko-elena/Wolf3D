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
# define WIDTH 800
# define HEIGHT 600

// ESC: for MAC OS key_code == 53; for Debian key_code == 65307
# define KEY_ESC 65307
// W: for MAC OS key_code == 13; for Debian key_code == 119
# define KEY_UP 119
// S: for MAC OS key_code == 1; for Debian key_code == 115
# define KEY_DOWN 115
// A: for MAC OS key_code == 0; for Debian key_code == 97
# define KEY_LEFT 97
// D: for MAC OS key_code == 2; for Debian key_code == 100
# define KEY_RIGHT 100
// SPACE: for MAC OS key_code == 49; for Debian key_code == 32
# define KEY_JUMP 32

// for int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
// x_mask is ignored on macos
# define KEY_PRESS_MASK (1L<<0)
// x_event set as 2 and funct set as an int key_press(int keycode, void *param) for a key press
# define KEY_PRESS 2

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
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
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
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
	int				start_x;
	int				start_y;
}					t_env;

int					main(int argc, char **argv);
int 				check_file(char *filename);
t_env				*init_env(void);
void				init_player(t_env *e);
void				event(t_env *env);
void				malloc_error(void);
int					loop_hook(t_env *env);




int					loop_hook(t_env *e);
int					open_file(t_env *e, char *f);
int					key_hook(int k, t_env *e);
int					key_press(int k, t_env *e);
int					key_release(int k, t_env *e);
void				draw_line(t_env *e, int x, int start, int end);
void				raycasting(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_jump(t_env *e);
void				error_map(void);
void				error_arg(void);

#endif
