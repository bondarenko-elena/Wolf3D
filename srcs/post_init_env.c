#include "../includes/wolf3d.h"

void	post_init_env(t_env *env)
{
	env->window = mlx_new_window(env->mlx_init, WIDTH, HEIGHT, "Wolf3D");
	env->image = mlx_new_image(env->mlx_init, WIDTH, HEIGHT);
	env->bits_per_pixel = 0;
	env->size_line = 0;
	env->get_data_addr = mlx_get_data_addr(env->image, &env->bits_per_pixel,
			&env->size_line, &env->endian);
	env->last_frame = clock();
	env->next_frame = 0;
}