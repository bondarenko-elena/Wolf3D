#include "../includes/wolf3d.h"

void		init_textures(t_env *env)
{
	int width;
	int height;

	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/brick.png", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/metal.png", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/wood.png", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/stone.png", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/sky.png", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/grass.png", &width, &height);
}