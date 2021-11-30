/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:55:58 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/30 20:02:31 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_flags	flags;
	t_args	arg;
	
	
	va_start(ap, fmt);
	flags.printlen = 0;
	while (*fmt)
	{
		if(*fmt == '%')
		{
			fmt++;
			ft_parse(&fmt, &flags, &arg, ap);
			ft_print(&flags, &arg);
		}
		else
		{
			ft_putchar_fd(*fmt++, STDOUT_FILENO);
			flags.printlen++;
		}
	}
	va_end(ap);
	return(flags.printlen);
}

////////////////////////////////////
////////////////////////////////////
////////////////////////////////////
#include <stdio.h>
#define PRINT "Hello2 	1"
int	main()
{
	printf("\nftprintlen: %d\n\n", ft_printf(PRINT));
	printf("\nprintlen: %d\n", printf(PRINT));
	return (0);
}