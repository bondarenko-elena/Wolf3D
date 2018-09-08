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
	tmp->color_1 = 0xff9600; // Orange Peel
	tmp->color_2 = 0x73ff00; // Lawn Green
	tmp->color_3 = 0xff00fc; // Magenta
	tmp->color_4 = 0x46fffc; //
	tmp->color_sky = 0x00cdff; // Deep Sky Blue
	tmp->color_ground = 0x2700ff; //
	return (tmp);	
}