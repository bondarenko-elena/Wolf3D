#include "../includes/wolf3d.h"

void		init_textures(t_env *env)
{
	int width;
	int height;

	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/brick.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/metal.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/wood.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/stone.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/sky.xpm", &width, &height);
	env->textures[0] = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/grass.xpm", &width, &height);
}