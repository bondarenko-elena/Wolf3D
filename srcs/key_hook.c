#include "../includes/wolf3d.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx_init, env->window);
		exit(0);
	}
	return (1);
}