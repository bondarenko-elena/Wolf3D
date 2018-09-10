#include "../includes/wolf3d.h"

void ray_casting(t_env *env)
{
	int		x;

	x = 0;
	// The ray starts at the position of the player (posX, posY)
	env->ray.position.x = env->player.position.x;
	env->ray.position.y = env->player.position.y;
	while (x < env->width)
	{
		ray_init(env, x);
		ray_calculate_step_side(env);
		ray_calculate_distance(env);
		ray_draw(env, x);
		x++;
	}
}