/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:59:14 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/10/29 15:54:20 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция ft_strsub распределяет (с помощью malloc) и
возвращает «свежую» подстроку из строки, заданной в качестве аргумента.
Подстрока начинается с start и имеет размер len.
Если start и len не ссылаются на допустимую подстроку, поведение не определено.
Если распределение завершается неудачно, функция возвращает NULL.
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	sublen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	sublen = 0;
	if (start < slen)
		sublen = slen - start;
	if (sublen > len)
		sublen = len;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (sub);
	ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
