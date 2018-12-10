/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:25:25 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/02 17:40:23 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char		*strjoin_gnl(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	len1;
// 	size_t	len2;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (s1 == NULL)
// 		len1 = 0;
// 	else
// 		len1 = ft_strlen(s1);
// 	if (s2 == NULL)
// 		len2 = 0;
// 	else
// 		len2 = ft_strlen(s2);
// 	if ((str = ft_strnew(len1 + ft_strlen(s2) + 1)) == NULL)
// 		return (NULL);
// 	(len1 == 0) ? str : ft_strcpy(str, s1);
// 	(len2 == 0) ? str : ft_strcpy((str + len1), s2);
// 	return (str);
// }

// t_list_my	*if_fd_exist(t_list_my **data, int fd)
// {
// 	t_list_my *lst;

// 	lst = *data;
// 	while (lst != NULL && lst->fd != fd)
// 		lst = lst->next;
// 	return (lst);
// }

// int			check_data(t_list_my **data, char *buff, int fd)
// {
// 	t_list_my	*current;
// 	char		*tmp;

// 	current = if_fd_exist(data, fd);
// 	if (current == NULL)
// 	{
// 		if (!(current = (t_list_my*)ft_lstnew((void*)buff, (
// 							ft_strlen(buff) + 1))))
// 			return (-1);
// 		current->fd = fd;
// 		ft_lstadd_back((t_list**)data, (t_list*)current);
// 	}
// 	else
// 	{
// 		if (!(tmp = strjoin_gnl((char*)current->content, buff)))
// 			return (-1);
// 		free(current->content);
// 		current->content = (void*)tmp;
// 		current->content_size = ft_strlen(tmp) + 1;
// 	}
// 	if (ft_strstr((char*)current->content, "\n") != NULL)
// 		return (1);
// 	return (0);
// }

// char		*get_data(t_list_my **data, int fd)
// {
// 	t_list_my	*curr;
// 	char		*head;
// 	char		*tail;
// 	char		*tmp;

// 	curr = if_fd_exist(data, fd);
// 	if (curr->content == NULL)
// 		return (NULL);
// 	if ((tail = ft_strstr((char*)curr->content, "\n")) != NULL)
// 	{
// 		if (!(head = ft_strsub((char*)curr->content,
// 						0, (curr->content_size - ft_strlen(++tail) - 2))))
// 			return (NULL);
// 		tmp = curr->content;
// 		curr->content = (ft_strlen(tail) == 0) ? NULL : (void *)ft_strdup(tail);
// 		curr->content_size = ft_strlen(tail) + 1;
// 		free(tmp);
// 	}
// 	else
// 	{
// 		if (!(head = ft_strdup((char *)curr->content)))
// 			return (NULL);
// 		SETNULL(curr->content, curr->content, curr->content_size);
// 	}
// 	return (head);
// }

// int			get_next_line(const int fd, char **line)
// {
// 	char				buff[BUFF_SIZE + 1];
// 	static t_list_my	*data = NULL;
// 	int					ret;
// 	int					res;

// 	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
// 		return (-1);
// 	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		if (ret < 0 || fd < 0)
// 			return (-1);
// 		buff[ret] = '\0';
// 		if ((res = check_data(&data, buff, fd)) == 1)
// 		{
// 			*line = get_data(&data, fd);
// 			return (1);
// 		}
// 		if (res == -1)
// 			return (-1);
// 	}
// 	if ((*line = get_data(&data, fd)) != NULL)
// 		return (1);
// 	return (0);
// }

int		line_verif(char **line, char **tmp, int res, char **str)
{
	if (res == 0 && ft_strlen(*tmp) > 0)
	{
		*line = *tmp;
		*str = NULL;
		*tmp = NULL;
		return (1);
	}
	if (res == 0 && ft_strlen(*tmp) == 0)
		return (0);
	return (res);
}

char	*read_line(char *tmp)
{
	size_t			t;
	char			*line;

	t = 0;
	while (tmp[t] != '\n')
		t++;
	line = (char *)malloc((t + 1) * sizeof(char));
	line = ft_strncpy(line, tmp, t);
	line[t] = '\0';
	return (line);
}

char	*cpycat(char *s1, char *s2)
{
	char *tmp;

	tmp = NULL;
	if ((s1 && !s2) || (!s1 && s2))
		return (s1 ? s1 : s2);
	if (!s1 && !s2)
		return (NULL);
	tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2));
	tmp = ft_strcpy(tmp, s1);
	tmp = ft_strncat(tmp, s2, ft_strlen(s2));
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static char				*str;
	int						res;
	char					*buf;
	char					*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (-1);
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (str == NULL)
		str = ft_strnew(BUFF_SIZE);
	tmp = ft_strncpy(ft_memalloc(BUFF_SIZE), str, BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((res = read(fd, buf, BUFF_SIZE)) < 1)
			return (line_verif(line, &tmp, res, &str));
		buf[res] = '\0';
		tmp = cpycat(tmp, buf);
	}
	*line = read_line(tmp);
	if (ft_strchr(tmp, '\n'))
		str = ft_strncpy(str, ft_strchr(tmp, '\n') + 1, BUFF_SIZE);
	free(tmp);
	free(buf);
	return (1);
}