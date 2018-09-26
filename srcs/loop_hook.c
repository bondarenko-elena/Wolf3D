#include "../includes/wolf3d.h"

int		loop_hook(t_env *env)
{
	env->mlx.last_frame = clock();
	if (env->mlx.next_frame > env->mlx.last_frame)
		return (0);
	env->mlx.next_frame = env->mlx.last_frame + (CLOCKS_PER_SEC / 100);
	if (env->player.move_up)
		move_up(env);
	if (env->player.move_down)
		move_down(env);
	if (env->player.move_right)
		move_right(env);
	if (env->player.move_left)
		move_left(env);
	if (env->player.move_jump == 1)
		move_jump(env);
	ray_casting(env);
	mlx_put_image_to_window(env->mlx.mlx_init, env->mlx.window, env->mlx.image, 0, 0);
	display_text(env);
	// mlx_destroy_image(env->mlx.mlx_init, env->mlx.image);
	return (0);
}