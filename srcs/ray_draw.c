#include "../includes/wolf3d.h"

void		ray_draw(t_env *env, int x)
{
	int		height;
	int		start;
	int		end;

	height = (int)(env->height / env->ray.distance);
	start = -height / 2 + env->height / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + env->height / 2;
	if (end >= env->height)
		end = env->height - 1;
	draw_line(env, x, start, end);
}