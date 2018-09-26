#include "../includes/wolf3d.h"

int		get_color_textured(t_env *env)
{
	int	color;
	int	c;

	c = (env->ray.step.y * env->textures[4]->width + env->ray.step.x) * 4;
	color = env->textures[4]->data[c];
	if (color == -120 && env->textures[4]->data[c + 1] == 0 && env->textures[4]->data[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += env->textures[4]->data[c + 1] * 256;
	color += env->textures[4]->data[c + 2] * 256 * 256;
	return (color);
}