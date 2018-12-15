/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:55 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	read_map(t_env *env)
{
	int		x;
	int		y;
	char	*line;
	char	**str_splitted;

	env->ray->map = (int **)malloc(sizeof(int *) * (env->ray->map_height));
	x = 0;
	while (x < env->ray->map_height && get_next_line(env->fd, &line) == 1)
	{
		str_splitted = ft_strsplit(line, ' ');
		env->ray->map[x] = (int *)malloc(sizeof(int) * (env->ray->map_width));
		y = 0;
		while (y < env->ray->map_width)
		{
			env->ray->map[x][y] = ft_atoi(str_splitted[y]);
			y++;
		}
		free(line);
		free_tab_char(str_splitted);
		x++;
	}
}
