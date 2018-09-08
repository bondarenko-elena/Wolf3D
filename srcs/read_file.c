#include "../includes/wolf3d.h"

void read_file(int fd, t_env *env)
{
	char *line;
	int y;
	int **map;

	y = 0;
	get_position(fd, env);
	map = (int **)malloc(sizeof(int **) * env->height);
	while (get_next_line(fd, &line) == 1)
	{
		// puts(line);
		read_line(line, y, map, env);
	}

	/*if (map[(int)env->player.position.x][(int)env->player.position.y] != 0)
	{
		map_error();
		printf("%d\n", 1);
	}*/

	env->map = map;
}