#include "../includes/wolf3d.h"

int open_file(t_env *env, char *filename)
{
	int fd;
	char *line;
	t_list *list;

	list = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd, &line) == 1)
		ft_lstadd_back(&list, ft_lstnew(line, ft_strlen(line)));
	if (!list)
		return (0);
	close(fd);
	read_file(env, list);
	return (0);
}