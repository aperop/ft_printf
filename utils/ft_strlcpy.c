/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:05:20 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/10/29 15:54:12 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	копирует из строки src в буфер dst не более чем size - 1 символов
	если size > 0 и запись символов состоится, 
	строка dst будет гарантированно нуль-терминирована.
	возвращает длину src
*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (len + 1 < size)
		ft_memcpy(dst, src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		*(dst + size - 1) = '\0';
	}
	return (len);
}
