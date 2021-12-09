/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:55:58 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/12/09 19:21:29 by dhawkgir         ###   ########.fr       */
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
		if (*fmt == '%')
		{
			fmt++;
			ft_parse(&fmt, &flags, &arg, ap);
			ft_print(&flags, &arg);
		}
		else
			ft_putchar(*fmt++, &flags);
	}
	va_end(ap);
	return (flags.printlen);
}
