#include "../includes/wolf3d.h"

void		ray_calculate_step_side(t_env *env)
{
	// what direction to step in x or y-direction (either +1 or -1)
	/* If the ray direction has a negative x-component, stepX is -1, if the ray direciton has a positive x-component it's +1.
	If the x-component is 0, it doesn't matter what value stepX has since it'll then be unused.
	The same goes for the y-component.
	*/
	if (env->ray.direction.x < 0)
	{
		env->ray.step.x = -1;
		env->ray.side.x = (env->ray.position.x - (int)env->ray.position.x) * env->ray.delta.x;  // * 2, to avoid strickted player in textures
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