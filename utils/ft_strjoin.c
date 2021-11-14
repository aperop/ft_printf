/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:58:28 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/10/29 15:54:10 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Функция ft_strjoin выделяет (с помощью malloc) и возвращает «свежую» строку,
	заканчивающуюся на \0, в результате объединения s1 и s2.
	Если распределение завершается неудачно, функция возвращает NULL.
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	count1;
	size_t	count2;
	char	*s;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	count1 = 0;
	count2 = 0;
	while (*(s1 + count1))
	{
		*(s + count1) = *(s1 + count1);
		count1++;
	}
	while (*(s2 + count2))
		*(s + count1++) = *(s2 + count2++);
	*(s + count1) = '\0';
	return (s);
}
