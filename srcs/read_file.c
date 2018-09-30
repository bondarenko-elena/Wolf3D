#include "../includes/wolf3d.h"

int		read_file(int fd, t_env *env)
{
	char	*line;
	int		y;
	int		**map;

	y = 0;
	get_position(fd, env);
	map = (int **)malloc(sizeof(int **) * env->map_height);
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, y, map, env);
		free(line);
		y++;
	}
	free(line);
	if (map[(int)env->player.position.x][(int)env->player.position.y] != 0)
	{
		while (env->map_height > -1)
		{
			// !!!
			free(map[env->map_height]);
			env->map_height--;
		}
		// !!!
		free(map);
		map_error();
	}
	env->map = map;
	return (1);
}