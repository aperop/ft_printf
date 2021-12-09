#include "ft_printf.h"

void    ft_processor(t_flags *flags, t_args *arg)
{
    if (flags->convertation != 'x' && flags->convertation != 'X')
        flags->hash = 0;
    if ((flags->convertation != 'd' && flags->convertation != 'i') || arg->integer < 0)
        flags->space = 0;
    if (flags->convertation == 'd' && flags->convertation == 'i')
        flags->plus= 0;
    if (flags->plus && flags->space)
        flags->space = 0;
    if (flags->zero && flags->align)
        flags->zero = 0;
    if ((flags->plus && arg->integer >= 0) || flags->space)
        (flags->width) -= 1;
    if (flags->hash)
        flags->width -= 2;
    if (ft_search(flags->convertation, "diuxX"))
        if (arg->integer == 0 && flags->precision == 0)
            flags->arglen = 0;
}

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
    flags->printlen++;
}

void    ft_putstr(char *str, t_flags *flags, int n)
{
    if(n == 0)
        return ;
    while (*str && n--)
        ft_putchar(*str++, flags);
}