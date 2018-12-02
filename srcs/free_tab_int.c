/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:51 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	free_tab_int(int **tab, int map_h)
{
	int	i;

	i = 0;
	while (i < map_h)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}
