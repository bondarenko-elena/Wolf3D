#include "../includes/wolf3d.h"

void			ray_casting(t_env *env)
{
	int		x;

	x = 0;
	// env->mlx.image = mlx_new_image(env->mlx.mlx_init, WIDTH, HEIGHT);
	// env->mlx.pixel = mlx_get_data_addr(env->mlx.image, &(env->mlx.bits_per_pixel), &(env->mlx.size_line),
	env->ray.position.x = env->player.position.x;
	env->ray.position.y = env->player.position.y;
	// textured sky // -> SEGFAULT
	// if (env->switch_textures == 1)
		// draw_sky(env);
	while (x < env->width)
	{
		ray_init(env, x);
		ray_calculate_step_side(env);
		ray_calculate_distance(env);
		ray_draw(env, x);
		x++;
	}
}