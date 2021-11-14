/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:59:08 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/10/29 15:54:19 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция ft_strtrim выделяет (с помощью malloc) и возвращает копию строки,
заданной в качестве аргумента, без пробелов в начале или конце строки.
Будут считаться пробелами символы из массива set.
Если у s нет пробелов в начале или в конце, функция возвращает копию s.
Если распределение завершается неудачно, функция возвращает NULL.
*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	if (start == end || end == 0)
		return (ft_strdup("\0"));
	while (ft_strchr(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
