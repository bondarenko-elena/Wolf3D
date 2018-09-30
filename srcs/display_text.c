#include "../includes/wolf3d.h"

void	display_text(t_env *env)
{
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 30, 0xffffff, "Control keys:");
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 45, 0xffffff, "Move - arrows or WASD");
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 60, 0xffffff, "Jump - space");
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 75, 0xffffff, "Switch music - M");
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 90, 0xffffff, "Mute - N");
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 105, 0xffffff, "Switch on textures - T");
	mlx_string_put(env->mlx.mlx_init, env->mlx.window, 10, 120, 0xffffff, "Reset textures - R");
}