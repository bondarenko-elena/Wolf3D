#include "../includes/wolf3d.h"

void put_pixel(t_env *env, int x, int y)
{
	int		color;

	color = (int)(env->color_ground * 256) % 256;
	color += ((int)(env->color_ground * 256) % 256) * 256;
	color += ((int)(env->color_ground * 256) % 256) * 256 * 256;
	mlx_pixel_put(env->mlx_init, env->window, x, y, color);
}
