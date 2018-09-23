#include "../includes/wolf3d.h"

void		init_textures(t_env *env)
{
	int width;
	int height;

	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/brick.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/metal.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/wood.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/stone.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/sky.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/grass.xpm", &width, &height);
}