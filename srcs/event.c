#include "../includes/wolf3d.h"

void event(t_env *env)
{
	mlx_key_hook(env->window, key_hook, env);
	// mlx_mouse_hook(env->window, mouse_hook, env);
	mlx_expose_hook(env->window, expose_hook, env);
}