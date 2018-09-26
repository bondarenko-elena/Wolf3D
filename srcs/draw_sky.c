#include "../includes/wolf3d.h"

void draw_sky(t_env *env)
{
	env->x_texture = 0;
	while (env->x_texture < env->width)
	{
		env->y_texture = 0;
		while (env->y_texture < env->height / 2)
		{
			ft_memcpy(env->mlx.image + 4 * env->width * env->y_texture + env->x_texture * 4, &env->textures[4].data[env->y_texture % 512 * env->textures[4].size_line + env->x_texture % 512 * env->textures[4].bits_per_pixel / 8], sizeof(int));
			env->y_texture++;
		}
		env->x_texture++;
	}
}