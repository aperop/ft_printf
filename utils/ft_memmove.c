/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:46:08 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/02 00:26:13 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция memmove копирует n байт из массива (области памяти),
на который указывает аргумент src, в массив (область памяти),
на который указывает аргумент dst.
При этом массивы (области памяти) могут пересекаться.
*/
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dst);
}
