#include "../includes/wolf3d.h"

int return_wall_three(t_env *env, int x, int i, int end)
{
	if (env->switch_textures == 1)
		return (65536 * 251 *  i * x * 256 / ((end + env->player.z) * env->height));
	if (env->switch_textures == 2)
			return (env->color_3 * (x % 16 && i % 16));
	return (env->color_3);
}