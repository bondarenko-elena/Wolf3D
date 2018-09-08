#include "../includes/wolf3d.h"

void read_line(char *line, int y, int **map, t_env *env)
{
	int x;
	char **str_splitted;

	x = 0;
	if (y >= env->map_height)
	{
		printf("%d\n", 6);
		map_error();
	}
	str_splitted = ft_strsplit(line, ' ');
/******************************************************************/
// puts(str_splitted[x]);
// write(1, &str_splitted[x][0], 1);
// write(1, "\n", 1);
// printf("ft_atoi(str_splitted[x]): %d\n", ft_atoi(str_splitted[x]));
/******************************************************************/
	map[y] = (int *)malloc(sizeof(int *) * env->width);
	while (str_splitted[x] != '\0')
	{
		if (!(str_splitted[x][0] >= '0' && str_splitted[x][0] <= '9' && ft_atoi(str_splitted[x]) >= 0 /*&& x < env->map_width*/))
		{
			printf("\nmap_error: %d\n", 7);
			map_error();
		}
		x++;
	}
	if (x != env->map_width)
	{
printf("x: %d\n", x);
printf("env->map_width: %d\n", env->map_width);


		printf("%d\n", 8);
		map_error();
	}
}