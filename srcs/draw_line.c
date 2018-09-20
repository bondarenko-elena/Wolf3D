#include "../includes/wolf3d.h"

void			draw_line(t_env *env, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	i = 0;
	c = ' ';
	c = get_color(env);
	c = add_smog(c, env->ray.distance);
	while (i < start + env->player.z)
	{
		put_pixel(env, x, i, env->color_sky);
		i++;
	}
	i--;
	while (i <= end + env->player.z && i < env->height)
	{
		put_pixel(env, x, i, c);
		i++;
	}
	i--;
	while (i < env->height)
	{
		put_pixel(env, x, i, add_smog(env->color_ground, abs(i - env->height) * 0.040));
		i++;
	}
}