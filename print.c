#include "ft_printf.h"

static void ft_print_space(t_flags *flags, t_args *arg)
{
	int count;

	if (flags->zero && !flags->dot)
		return ;
	count = 0;
	if (ft_search(flags->convertation, "sc%"))
		if(!flags->zero && flags->precision < flags->arglen)
			if(flags->precision >= 0)
				count = flags->width - flags->precision;
			else
				count = flags->width - flags->arglen;
		else
			count = flags->width - flags->arglen;
	else
		if (arg->integer < 0)
			flags->width -= 1;
		if (flags->convertation == 'p')
			flags->width -= 2;
		if (flags->arglen < flags->precision)
			count = flags->width - flags->precision;
		else
			count = flags->width - flags->arglen;
	while (count-- > 0)
		ft_putchar(' ', flags);
}

static void ft_print_prefix(t_flags *flags, t_args *arg)
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
	else if (ft_search(flags->convertation, "xX") && flags->hash && arg->integer)
	{
		if (flags->convertation == 'x')
			ft_putstr("0x", flags, -42);
		if (flags->convertation == 'X')
			ft_putstr("0X", flags, -42);
	}
	
}

static void ft_print_zero(t_flags *flags, t_args *arg)
{
	int	count;

	count = 0;
	if (ft_search(flags->convertation, "diuxXp%"))
	{
		if (flags->zero && !flags->dot)
		{
			count = flags->width - flags->arglen;
			if (arg->integer < 0)
				count--;
			if (flags->arglen == 0)
				count = 0;
		}
		else
			count = flags->precision - flags->arglen;
	}
	while (count-- > 0)
		ft_putchar('0', flags);
}

static void	ft_print_arg(t_flags *flags, t_args *arg)
{
	if ((flags->convertation == 'd' || flags->convertation == 'i') && !(arg->integer == 0 && flags->precision == 0))
		ft_putnbr(arg->integer, flags);
	else if (flags->convertation == 's')
		ft_putstr(arg->str, flags, flags->precision);
	else if (flags->convertation == 'c')
		ft_putchar(arg->symbol, flags);
	else if (flags->convertation == '%')
		ft_putchar('%', flags);
	else if (flags->convertation == 'u' && !(arg->integer == 0 && flags->precision == 0))
		ft_putnbr_unsigned(arg->integer, "0123456789", flags);
	else if (flags->convertation == 'x' && !(arg->integer == 0 && flags->precision == 0))
		ft_putnbr_unsigned(arg->integer, "0123456789abcdef", flags);
	else if (flags->convertation == 'X' && !(arg->integer == 0 && flags->precision == 0))
		ft_putnbr_unsigned(arg->integer, "0123456789ABCDEF", flags);
	else if (flags->convertation == 'p')
		ft_putaddr(arg->integer, 0,)
	
}

void    ft_print(t_flags *flags, t_args *arg)
{
	if (!flags->align)
		ft_print_space(flags, arg);
	ft_print_prefix(flags, arg);
	ft_print_zero(flags, arg);
	ft_print_arg(flags, arg);
	if (flags->align)
		ft_print_space(flags, arg);
}