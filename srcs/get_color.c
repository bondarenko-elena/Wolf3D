#include "../includes/wolf3d.h"

unsigned int	get_color(t_env *env)
{
	if (env->ray.hit_side == 1)
	{
		if ((env->ray.step.x == -1 && env->ray.step.y == -1) ||
			(env->ray.step.x == 1 && env->ray.step.y == -1))
			return (env->color_1);
		if ((env->ray.step.x == -1 && env->ray.step.y == 1) ||
			(env->ray.step.x == 1 && env->ray.step.y == 1))
			return (env->color_2);
	}
	if ((env->ray.step.x == -1 && env->ray.step.y == -1) ||
		(env->ray.step.x == -1 && env->ray.step.y == 1))
		return (env->color_3);
	return (env->color_4);
}