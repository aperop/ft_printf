/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:10:37 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/12/09 20:37:25 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->printlen++;
}

void	ft_putstr(char *str, t_flags *flags, int n)
{
	if (n == 0)
		return ;
	while (*str && n--)
		ft_putchar(*str++, flags);
}

void	ft_putnbr(int n, t_flags *flags)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10, flags);
	ft_putchar(nb % 10 + 48, flags);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	ft_print_prefix(t_flags *flags, t_args *arg)
{
	if (ft_search(flags->convertation, "diu"))
	{
		if (flags->space)
			ft_putchar(' ', flags);
		if (arg->integer < 0)
			ft_putchar('-', flags);
		else if (flags->plus)
			ft_putchar('+', flags);
	}
	else if (ft_search(flags->convertation, "xX") \
				&& flags->hash && arg->integer)
	{
		if (flags->convertation == 'x')
			ft_putstr("0x", flags, -21);
		if (flags->convertation == 'X')
			ft_putstr("0X", flags, -21);
	}
}
