#include "../includes/wolf3d.h"

void		init_player(t_env *env)
{
	env->player.position.x = 0;
	env->player.position.y = 0;
	env->player.direction.x = -1;
	env->player.direction.y = 0;
	env->player.z = 0;
	env->player.plane.x = 0;
	env->player.plane.y = 0.66;
	env->player.speed_turn = 0.05;
	env->player.speed_move = 0.05;
	env->player.move_up = 0;
	env->player.move_down = 0;
	env->player.move_right = 0;
	env->player.move_left = 0;
	env->player.move_jump = 0;
	env->player.is_jump = 0;
}