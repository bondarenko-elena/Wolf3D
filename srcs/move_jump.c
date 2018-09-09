#include "../includes/wolf3d.h"

void move_jump(t_env *env)
{
	if (env->player.z >= 100)
		env->player.is_jump = 1;
	if (env->player.is_jump == 1)
		env->player.z =  env->player.z - 10;
	if (env->player.is_jump == 0)
		env->player.z = env->player.z + 10;
	if (env->player.is_jump == 1 && env->player.z == 0)
	{
		env->player.is_jump = 0;
		env->player.move_jump = 0;
	}
}