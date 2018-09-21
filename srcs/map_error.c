#include "../includes/wolf3d.h"

void	map_error(void)
{
	write(1, "map error\n", 10);
	exit(1);
}
