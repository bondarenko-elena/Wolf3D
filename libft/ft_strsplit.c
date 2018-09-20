/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:44:51 by adespond          #+#    #+#             */
/*   Updated: 2016/01/13 12:47:39 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_count_word_sep(char const *s, char c)
{
	unsigned int	word;
	unsigned int	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			word++;
	}
	return (word);
}

static char				*ft_malloc_word(char const *s, size_t start, size_t len)
{
	char			*s1;
	unsigned int	i;

	i = 0;
	s1 = (char *)malloc(len + 1);
	if (s1 == NULL)
		return (NULL);
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**ret;
	unsigned int	word;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (s == NULL)
		return (NULL);
	word = ft_count_word_sep(s, c);
	ret = (char **)malloc(sizeof(char *) * word + 1);
	ret[word] = 0;
	word = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0' && ++len > 0)
			i++;
		if (s[i - 1] != c)
			ret[word++] = ft_malloc_word(s, i - len, len);
	}
	return (ret);
}
