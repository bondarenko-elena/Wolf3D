#include "../includes/wolf3d.h"

void draw_sky(t_env *env, int x, int y)
{
	ft_memcpy(t->img_ptr + 4 * WINX * t->y_text + t->x_text * 4, &t->tex[6].data[t->y_text % 512 * t->tex[6].sizeline +	t->x_text % 512 * t->tex[6].bpp / 8], sizeof(int));
}