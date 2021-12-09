/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:10:56 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/12/09 20:07:16 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flags *flags, t_args *arg)
{
	flags->align = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->precision = -1;
	flags->width = 0;
	flags->arglen = 0;
	arg->symbol = 0;
	arg->str = NULL;
	arg->integer = 0;
	arg->base = NULL;
}

int	ft_nbr_digit(long long n, char *base)
{
	int			i;
	long long	len;

	len = ft_strlen(base);
	i = 1;
	if (len <= 1)
		return (0);
	while (n >= len)
	{
		n /= len;
		i++;
	}
	return (i);
}

int	ft_nbr_digit_unsigned(unsigned long n, char *base)
{
	int				i;
	unsigned long	len;

	len = ft_strlen(base);
	i = 1;
	if (len <= 1)
		return (0);
	while (n >= len)
	{
		n /= len;
		i++;
	}
	return (i);
}

int	ft_search(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int	ft_width(const char **fmt)
{
	int	width;

	width = 0;
	while (**fmt && (**fmt) >= '0' && (**fmt) <= '9')
	{
		width = (width * 10) + (**fmt) - '0';
		(*fmt)++;
	}
	return (width);
}
