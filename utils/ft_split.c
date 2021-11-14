/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:58:10 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/02 00:56:19 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция ft_split выделяет (с помощью malloc) и возвращает массив «свежих» строк
(все заканчивающиеся на \0, включая сам массив),
полученных путем разбиения s с использованием символа c в качестве разделителя.
Если распределение завершается неудачно, функция возвращает NULL. 
*/
#include "libft.h"

static unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	count;
	unsigned int	index;

	count = 0;
	index = 0;
	while (*(s + index))
	{
		if (*(s + index) == c)
			index++;
		else
		{
			count++;
			while (*(s + index) && *(s + index) != c)
				index++;
		}
	}
	return (count);
}

static unsigned int	ft_wordlen(char const *s, char c)
{
	unsigned int	index;

	index = 0;
	while (*(s + index) && *(s + index) != c)
		index++;
	return (index);
}

static char	**ft_free(char **str, int count)
{
	while (count)
	{
		free(*(str + count));
		count--;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	wrdcnt;
	unsigned int	index;
	char			**strsplit;

	wrdcnt = 0;
	index = 0;
	if (s && *s)
		wrdcnt = ft_countwords(s, c);
	strsplit = (char **)malloc((wrdcnt + 1) * sizeof(char *));
	if (!strsplit)
		return (0);
	while (wrdcnt--)
	{
		while (*s && *s == c)
			s++;
		*(strsplit + index) = ft_substr(s, 0, ft_wordlen(s, c));
		if (!*(strsplit + index))
			return (ft_free(strsplit, index));
		s = s + ft_wordlen(s, c);
		index++;
	}
	*(strsplit + index) = 0;
	return (strsplit);
}
