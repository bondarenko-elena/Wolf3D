#include "../includes/wolf3d.h"

void			draw_line(t_env *env, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	i = 0;
	c = get_color(env);
	// c = add_smog(c, env->ray.distance);
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
/*	while (i < e->height)
	{
		put_pixel(e, x, i, add_smog(e->color_ground, abs(i - e->height) * 0.040));
		i++;
	}*/
}