#include "../includes/wolf3d.h"

int return_wall_one(t_env *env, int x, int i, int end)
{
	if (env->switch_textures == 1)
		return ((65536 * 251  *  i * x * 4 / (env->height / end)) >> 4);
	if (env->switch_textures == 2)
		return (env->color_1 * (x % 16 && i % 16));
	return (env->color_1);
}