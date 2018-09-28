#include "../includes/wolf3d.h"

int return_wall_two(t_env *env, int x, int i, int end)
{
	if (env->switch_textures == 1)
		return (65536 * 251  *  i * x * 4 / (env->height / end));
	if (env->switch_textures == 2)
		return (env->color_2 * (x % 16 && i % 16));
	return (env->color_2);
}