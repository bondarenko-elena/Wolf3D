/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:42 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:45:05 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	check_file(t_env *env)
{
	char	*line;
	char	**str_splitted;

	line = NULL;
	get_next_line(env->fd, &line);
	if (!line)
		map_error();
	str_splitted = ft_strsplit(line, ' ');
	while (str_splitted[env->check_chars])
		env->check_chars++;
	if (!(check_line(line)) || !(check_map(env)))
	{
		free(line);
		free_tab_char(str_splitted);
		return (0);
	}
	if (env->ray->map_height > 100 || env->ray->map_height < 4)
		map_error();
	if (env->ray->map_width > 100 || env->ray->map_width < 4)
		map_error();
	free_tab_char(str_splitted);
	free(line);
	return (1);
}
