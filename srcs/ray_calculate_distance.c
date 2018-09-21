#include "../includes/wolf3d.h"

void		ray_calculate_distance(t_env *env)
{
	while (env->ray.hit == 0)
	{
		if (env->ray.side.x < env->ray.side.y)
		{
			env->ray.side.x += env->ray.delta.x;
			env->ray.map.x += env->ray.step.x;
			env->ray.hit_side = 0;
		}
		else
		{
			env->ray.side.y += env->ray.delta.y;
			env->ray.map.y += env->ray.step.y;
			env->ray.hit_side = 1;
		}
		if (env->map[env->ray.map.x][env->ray.map.y] > 0)
		{
			env->ray.hit = 1;
			if (env->ray.hit_side == 0)
				env->ray.distance = (env->ray.map.x - env->ray.position.x + (1 - env->ray.step.x)
						/ 2) / env->ray.direction.x;
			else
				env->ray.distance = (env->ray.map.y - env->ray.position.y + (1 - env->ray.step.y)
						/ 2) / env->ray.direction.y;
		}
	}
}