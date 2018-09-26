#include "../includes/wolf3d.h"

t_env			*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		malloc_error();
	env->width = WIDTH;
	env->height = HEIGHT;
	init_player(env);
	env->mlx.mlx_init = mlx_init();
	env->mlx.bits_per_pixel = 0;
	env->mlx.size_line = 0;
	env->mlx.image = mlx_new_image(env->mlx.mlx_init, WIDTH, HEIGHT);
	env->mlx.pixel = mlx_get_data_addr(env->mlx.image, &(env->mlx.bits_per_pixel), &(env->mlx.size_line),
			&(env->mlx.endian));
	env->mlx.last_frame = clock();
	env->mlx.next_frame = 0;
	env->color_1 = 0x0000ff;
	env->color_2 = 0xff0000;
	env->color_3 = 0x00ffff;
	env->color_4 = 0x00ff00;
	env->color_sky = 0x92d9f5;
	env->color_ground = 0x19191a;
	env->switch_textures = 0; // textures is off
	env->x_texture = 0;
	env->y_texture = 0;
	init_textures(env);
	return (env);
}