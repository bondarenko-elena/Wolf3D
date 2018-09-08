#include "../includes/wolf3d.h"

t_env	*pre_init_env()
{
	t_env *tmp;

	if ((tmp = (t_env*)malloc(sizeof(t_env))) == NULL)
		malloc_error();
	tmp->mlx_init = mlx_init();
	tmp->screen_name = "Wolf3D@42";
	tmp->width = WIDTH;
	tmp->height = HEIGHT;
	return (tmp);	
}