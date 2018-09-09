#include "../includes/wolf3d.h"

void ray_init(t_env *env, int x)
{
	env->ray.map.x = (int)env->ray.position.x;
	env->ray.map.y = (int)env->ray.position.y;
	env->ray.camera = 2 * x / (double)env->width - 1;
	env->ray.direction.x = env->player.direction.x + env->player.plane.x * env->ray.camera;
	env->ray.direction.y = env->player.direction.y + env->player.plane.y * env->ray.camera;
	env->ray.delta.x = sqrt(1 + (env->ray.direction.y * env->ray.direction.y) /
			(env->ray.direction.x * env->ray.direction.x));
	env->ray.delta.y = sqrt(1 + (env->ray.direction.x * env->ray.direction.x) /
			(env->ray.direction.y * env->ray.direction.y));
	env->ray.hit = 0;
	env->ray.distance = -1;
	env->ray.hit_side = -1;
}