#include "../includes/wolf3d.h"

int expose_hook(t_env *env)
{
/*	env->last_frame = clock();
	if (env->next_frame > env->last_frame)
		return (0);
	env->next_frame = env->last_frame + (CLOCKS_PER_SEC / 100);
*/
	if (env->player.move_up == 1)
		move_up(env);
	if (env->player.move_down == 1)
		move_down(env);
	if (env->player.move_left == 1)
		move_left(env);
	if (env->player.move_right == 1)
		move_right(env);


	// ray_casting(env);
	mlx_put_image_to_window(env->mlx_init, env->window, env->image, 0, 0);
	return (0);
}