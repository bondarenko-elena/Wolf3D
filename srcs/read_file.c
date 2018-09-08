#include "../includes/wolf3d.h"

void read_file(t_env *env, t_list *list)
{
	while (list)
	{
		if (ft_strstr(list->content, "scene"))
		{
			puts(env->screen_name);
		}
		else if (ft_strstr(list->content, "content"))
		{
			puts(list->content);
		}
		list = list->next;
	}
}