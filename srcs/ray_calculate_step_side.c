#include "../includes/wolf3d.h"

void		ray_calculate_step_side(t_env *env)
{
	if (env->ray.direction.x < 0)
	{
		env->ray.step.x = -1;
		env->ray.side.x = (env->ray.position.x - (int)env->ray.position.x) * env->ray.delta.x;
	}
	else
	{
		env->ray.step.x = 1;
		env->ray.side.x = ((int)env->ray.position.x + 1 - env->ray.position.x) * env->ray.delta.x;
	}
	if (env->ray.direction.y < 0)
	{
		env->ray.step.y = -1;
		env->ray.side.y = (env->ray.position.y - (int)env->ray.position.y) * env->ray.delta.y;
	}
	else
	{
		env->ray.step.y = 1;
		env->ray.side.y = ((int)env->ray.position.y + 1 - env->ray.position.y) * env->ray.delta.y;
	}
}