#include "../includes/wolf3d.h"

void			draw_line(t_env *env, int x, int start, int end)
{
	int				i;
	unsigned int	c;
	// int 			c_textured;
	// int 			random;

	// srand(time(NULL));
	c = get_color(env);
	c = add_smog(c, env->ray.distance);
	//////////
	// c_textured = get_color_textured(env);
	//////////
	i = -1;
	// sky
	while (++i < start + env->player.z)
	{
		if (env->switch_textures == 0)
			put_pixel(env, x, i, env->color_sky);
		// if (env->switch_textures == 1)
		// {
			// put_pixel(env, x, i, c_textured);
		// }
	}
	i--;
	while (++i <= end + env->player.z && i < env->height)
		put_pixel(env, x, i, c);
	i--;
	while (++i < env->height)
		put_pixel(env, x, i, add_smog(env->color_ground, abs(i - env->height) * 0.040));
}