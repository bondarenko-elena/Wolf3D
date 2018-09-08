#include "../includes/wolf3d.h"

int expose_hook(t_env *env)
{
	display(env);
	return (1);
}