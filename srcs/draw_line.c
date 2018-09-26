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
			put_pixel(env, x + 5, i, c * (x % 16 && i % 16));
		}
	}
	i--;
	// walls //
	while (++i < env->height)
		put_pixel(env, x, i, add_smog(env->color_ground, abs(i - env->height) * 0.040));
}


/*
bricks						---> put_pixel(env, x + 5, i, c * (x % 16 && i % 16));
gradient 					---> put_pixel(env, x, i, c >> 5);
*/