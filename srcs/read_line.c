#include "../includes/wolf3d.h"

void read_line(char *line, int y, t_env *env)
{
	int x;
	char **str_splitted;

	x = 0;
	str_splitted = ft_strsplit(line, ' ');
	env->map[y] = (int*)malloc(sizeof(int*) * env->check_chars);
	while (str_splitted[x])
	{
		env->map[y][x] = ft_atoi(str_splitted[x]);
		x++;
	}
	if (y >= env->map_height)
	{
		printf("%d\n", 6);
		map_error();
	}
	if (x != env->map_width)
	{
		printf("%d\n", 8);
		map_error();
	}
}