/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:49 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:48:00 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	check_map(t_env *env)
{
	int		i;
	int		str_len;
	char	*str;
	char	**str_splitted;

	i = 1;
	str_splitted = NULL;
	while (get_next_line(env->fd, &str) > 0)
	{
		str_len = 0;
		str_splitted = ft_strsplit(str, ' ');
		while (str_splitted[str_len])
			str_len++;
		if (str_len != env->check_chars)
		{
			free_tab_char(str_splitted);
			free(str);
			return (0);
		}
		if (!(check_map2(str_len, str_splitted, str)))
			return (0);
		i++;
	}
	init_map_size(env, i);
	return (1);
}
