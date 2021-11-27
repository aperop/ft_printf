/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:55:58 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/27 22:51:24 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_vprintf(const char *fmt, va_list ap)
{
	return (1);
}
int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;
	
	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if(*fmt != '%')
		{
			ft_putchar_fd(*fmt, STDOUT_FILENO);
			len++;
		}
		else
			len += ft_vprintf(fmt, ap);
		fmt++;
	}
	va_end(ap);
	return(len);
}


#include <stdio.h>
#define PRINT "%d", 34
int	main()
{
	printf("\nftprintlen: %d\n\n", ft_printf(PRINT));
	printf("\nprintlen: %d\n", printf(PRINT));
	return (0);
}