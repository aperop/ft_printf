/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:55:58 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/28 18:49:56 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int	ft_vprintf(const char *fmt, va_list ap)
{
	if (*fmt == 'c')
		ft_putchar_fd(va_arg(ap, int), STDOUT_FILENO);
	if (*fmt == '%')
		ft_putchar_fd(*fmt, STDOUT_FILENO);
	if (*fmt == 's')
		ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
	// if (*fmt == 'p')
	// 	ft_put_fd(va_arg(ap, char), STDOUT_FILENO);
	if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO);
	// if (*fmt == 'u')
	// 	ft_put(va_arg(ap, char), STDOUT_FILENO);
	// if (*fmt == 'x')
	// 	ft_put(va_arg(ap, char), STDOUT_FILENO);
	// if (*fmt == 'X')
	// 	ft_put(va_arg(ap, char), STDOUT_FILENO);

	return (42);
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
			len += ft_vprintf(++fmt, ap);
		fmt++;
	}
	va_end(ap);
	return(len);
}


#define PRINT "%%"
int	main()
{
	printf("\nftprintlen: %d\n\n", ft_printf(PRINT));
	printf("\nprintlen: %d\n", printf("%2000.0008%"));
	return (0);
}