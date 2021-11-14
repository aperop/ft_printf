/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:58:58 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/10/29 15:54:15 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция ft_strmapi применяет функцию f к каждому символу строки s,
переданной в качестве аргумента, указав ее индекс в качестве первого аргумента,
чтобы создать «свежую» новую строку (с malloc),
полученную в результате последовательного применения f.
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (*(s + i) && f)
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
