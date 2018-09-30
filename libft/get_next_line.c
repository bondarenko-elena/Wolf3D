/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 10:58:13 by olbondar          #+#    #+#             */
/*   Updated: 2018/09/30 10:59:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_data	*new_data(int fd)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->last = ft_strnew(BUFF_SIZE);
	data->next = NULL;
	data->fd = fd;
	data->end = 0;
	return (data);
}

static t_data	*get_data(t_data *begin_data, int fd)
{
	t_data	*data;

	data = begin_data;
	while (data)
	{
		if (data->fd == fd)
		{
			return (data);
		}
		if (data->next == NULL)
		{
			data->next = new_data(fd);
			return (data->next);
		}
		data = data->next;
	}
	return (NULL);
}

static int		ft_read(t_data *data, char *buff, int ret, char **line)
{
	if (data->end == 1)
		return (0);
	ret = read(data->fd, buff, BUFF_SIZE);
	if (ret <= 0 && *line[0] == '\0')
		return (ret);
	buff[BUFF_SIZE] = '\0';
	if (ret < BUFF_SIZE)
		data->end = 1;
	return (1);
}

static int		ft_line(t_data *data, char *buff, char **line, int ret)
{
	buff = data->last;
	data->last = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (buff[0] == '\0' && (ret = ft_read(data, buff, ret, line)) != 1)
			return (ret);
		if ((data->last = ft_strchr(buff, '\n')) != NULL)
		{
			data->last++;
			buff = ft_strsub(buff, 0, ft_strchrpos(buff, '\n'));
			*line = ft_strjoin(*line, buff);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, buff);
			buff = ft_strnew(BUFF_SIZE);
			if (data->end == 1)
			{
				data->last = ft_strnew(BUFF_SIZE);
				return (1);
			}
		}
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_data	*begin_data;
	t_data			*data;
	char			*buff;
	int				ret;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (begin_data == NULL)
		begin_data = new_data(fd);
	buff = ft_strnew(BUFF_SIZE);
	data = get_data(begin_data, fd);
	*line = ft_strnew(BUFF_SIZE);
	ret = ft_line(data, buff, line, ret);
	return (ret);
}
