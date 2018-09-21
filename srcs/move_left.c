#include "../includes/wolf3d.h"

void	move_left(t_env *env)
{
	t_dir_xy	old;

	old.x = env->player.direction.x;
	env->player.direction.x = env->player.direction.x * cos(env->player.speed_turn) -
		env->player.direction.y * sin(env->player.speed_turn);
	env->player.direction.y = old.x * sin(env->player.speed_turn) + env->player.direction.y *
		cos(env->player.speed_turn);
	old.x = env->player.plane.x;
	env->player.plane.x = env->player.plane.x * cos(env->player.speed_turn) -
		env->player.plane.y * sin(env->player.speed_turn);
	env->player.plane.y = old.x * sin(env->player.speed_turn) + env->player.plane.y *
		cos(env->player.speed_turn);
}