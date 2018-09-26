#include "../includes/wolf3d.h"

void		init_textures(t_env *env)
{
	int width;
	int height;

	width = 64;
	height = 64;

	env->textures[0].image = mlx_xpm_file_to_image(env->mlx.mlx_init,	"textures/wood.xpm", &width, &height);
	// env->textures[0]->data = mlx_get_data_addr(env->textures[0]->image, &(env->textures[0]->bits_per_pixel), &(env->textures[0]->size_line), &(env->textures[0]->endian));

/*	env->textures[1]->image = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/metal.xpm", &width, &height);
	env->textures[1]->data = mlx_get_data_addr(env->textures[1]->image, &(env->textures[1]->bits_per_pixel), &(env->textures[1]->size_line), &(env->textures[1]->endian));

	env->textures[2]->image = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/brick.xpm", &width, &height);
	env->textures[2]->data = mlx_get_data_addr(env->textures[2]->image, &(env->textures[2]->bits_per_pixel), &(env->textures[2]->size_line), &(env->textures[2]->endian));

	env->textures[3]->image = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/brick.xpm", &width, &height);
	env->textures[3]->data = mlx_get_data_addr(env->textures[3]->image, &(env->textures[3]->bits_per_pixel), &(env->textures[3]->size_line), &(env->textures[3]->endian));

	env->textures[4]->image = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/brick.xpm", &width, &height);
	env->textures[4]->data = mlx_get_data_addr(env->textures[4]->image, &(env->textures[4]->bits_per_pixel), &(env->textures[4]->size_line), &(env->textures[4]->endian));

	env->textures[5]->image = mlx_xpm_file_to_image(env->mlx.mlx_init,	"../textures/xpm/brick.xpm", &width, &height);
	env->textures[5]->data = mlx_get_data_addr(env->textures[5]->image, &(env->textures[5]->bits_per_pixel), &(env->textures[5]->size_line), &(env->textures[5]->endian));
*/

}