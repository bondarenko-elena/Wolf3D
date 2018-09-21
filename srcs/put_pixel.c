#include "../includes/wolf3d.h"

void			put_pixel(t_env *env, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * env->mlx.size_line);
	env->mlx.pixel[i] = c;
	env->mlx.pixel[++i] = c >> 8;
	env->mlx.pixel[++i] = c >> 16;
}