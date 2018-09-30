#include "../includes/wolf3d.h"

int	close_program(t_env *env)
{
	mlx_destroy_image(env->mlx.mlx_init, env->mlx.image);
	system("killall afplay");
	while (env->map_height > -1)
	{
		free(env->map[env->map_height]);
		env->map_height--;
	}
	free(env->map);
	free(env);
	exit(0);
	return (0);
}