/*
1 - bricks									---> put_pixel(env, x, i, c * (x % 16 && i % 16));
2 - abstract weave blue						---> put_pixel(env, x, i, 65536 *  i * x * 256 / ((end + env->player.z) * env->height));
3 - abstract weave red						---> put_pixel(env, x, i, 65536 *  i * x * 4 / (env->height / end));
4 - abstract strips 						---> put_pixel(env, x, i, 65536 *  i * x * 4 / ((end + env->player.z) * env->width));
5 - abstract weave + abstract strips red	---> put_pixel(env, x, i, 65536 *  i * x * 4 / ((end) - env->width));
6 - abstract weave + abstract strips green	---> put_pixel(env, x, i, 65536 *  i * x * 4 / (env->width));

7 - gradient 								---> put_pixel(env, x, i, c >> 5);
*/

#include "../includes/wolf3d.h"

unsigned int	get_color(t_env *env, int x, int i, int end)
{
	if (env->ray.hit_side == 1)
	{
		if ((env->ray.step.x == -1 && env->ray.step.y == -1) ||	(env->ray.step.x == 1 && env->ray.step.y == -1))
		{
			if (env->switch_textures == 0)
				return (env->color_1);
			if (env->switch_textures == 1)
				return (65536 *  i * x * 4 / (env->height / end));
			if (env->switch_textures == 2)
				return (env->color_1 * (x % 16 && i % 16));
		}
		if ((env->ray.step.x == -1 && env->ray.step.y == 1) ||	(env->ray.step.x == 1 && env->ray.step.y == 1))
		{
			if (env->switch_textures == 0)
				return (env->color_2);
			if (env->switch_textures == 1)
				return (65536 *  i * x * 4 / ((end + env->player.z) * env->width));
			if (env->switch_textures == 2)
				return (env->color_2 * (x % 16 && i % 16));
		}
	}
	if ((env->ray.step.x == -1 && env->ray.step.y == -1) ||	(env->ray.step.x == -1 && env->ray.step.y == 1))
	{
		if (env->switch_textures == 0)
			return (env->color_3);
		if (env->switch_textures == 1)
			return (65536 *  i * x * 4 / ((end) - env->width));
		if (env->switch_textures == 3)
				return (env->color_2 * (x % 16 && i % 16));
	}
	if (env->switch_textures == 1)
		return (65536 *  i * 2 * x * 4 / (env->width));
	if (env->switch_textures == 2)
				return (env->color_4 * (x % 16 && i % 16));
	return (env->color_4);
}