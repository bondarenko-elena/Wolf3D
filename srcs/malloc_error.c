#include "../includes/wolf3d.h"

void	malloc_error(void)
{
	write(1, "malloc error\n", 13);
	exit(1);
}