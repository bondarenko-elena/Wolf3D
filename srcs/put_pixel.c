#include "../includes/wolf3d.h"

void put_pixel(t_env *env, int x, int y)
{
	int		color;

	color = (int)(env->color_ground * 256) % 256;
	color += ((int)(env->color_ground * 256) % 256) * 256;
	color += ((int)(env->color_ground * 256) % 256) * 256 * 256;
	mlx_pixel_put(env->mlx_init, env->window, x, y, color);
}



void			put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = c;
	e->mlx.pxl[++i] = c >> 8;
	e->mlx.pxl[++i] = c >> 16;
}