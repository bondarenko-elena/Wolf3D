#include "../includes/wolf3d.h"

void			draw_line(t_env *env, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = get_color(env);
	c = add_smog(c, env->ray.distance);
	i = -1;

	// sky //
	while (++i < start + env->player.z)
	{
		if (env->switch_textures == 0)
			put_pixel(env, x, i, env->color_sky);
		if (env->switch_textures == 1)
		{
			put_pixel(env, x, i, env->color_sky);
		}
	}
	i--;
	// ground //
	while (++i <= end + env->player.z && i < env->height)
	{
		if (env->switch_textures == 0)
			put_pixel(env, x, i, c);
		if (env->switch_textures == 1)
		{
			put_pixel(env, x, i, 65536 *  i * x * 4 / (env->height / end));
		}
	}
	i--;
	// walls //
	while (++i < env->height)
		put_pixel(env, x, i, add_smog(env->color_ground, abs(i - env->height) * 0.040));
}


/*
gradient 								---> put_pixel(env, x, i, c >> 5);
bricks									---> put_pixel(env, x, i, c * (x % 16 && i % 16));
abstract weave blue						---> put_pixel(env, x, i, 65536 *  i * x * 256 / ((end + env->player.z) * env->height));
abstract weave red						---> put_pixel(env, x, i, 65536 *  i * x * 4 / (env->height / end));
abstract strips 						---> put_pixel(env, x, i, 65536 *  i * x * 4 / ((end + env->player.z) * env->width));
abstract weave + abstract strips red	---> put_pixel(env, x, i, 65536 *  i * x * 4 / ((end) - env->width));
abstract weave + abstract strips green	---> put_pixel(env, x, i, 65536 *  i * x * 4 / (env->width));

black 0x000000
white 0xffffff
*/