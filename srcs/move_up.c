#include "../includes/wolf3d.h"

void	move_up(t_env *env)
{
	if (env->map[(int)(env->player.position.x + env->player.direction.x * env->player.speed_move)]
			[(int)env->player.position.y] == 0)
		env->player.position.x += env->player.direction.x * env->player.speed_move;
	if (env->map[(int)env->player.position.x][(int)(env->player.position.y + env->player.direction.y *
				env->player.speed_move)] == 0)
		env->player.position.y += env->player.direction.y * env->player.speed_move;
}