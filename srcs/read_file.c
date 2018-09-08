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
		read_line(line, y, map, env);
		y++;
	}
	puts("piu!");
	/*if (map[(int)env->player.position.x][(int)env->player.position.y] != 0)
	{
		map_error();
		printf("%d\n", 1);
	}*/

/*	puts("piu!");
	int i = 0;
	int j;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf(" %d", map[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
*/
	env->map = map;
}