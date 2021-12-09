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

void    ft_putnbr_unsigned(unsigned int number, char *base, t_flags *flags)
{
    if (number >= ft_strlen(base))
        ft_putnbr_unsigned(number / ft_strlen(base), base, flags);
    ft_putchar(base[number % ft_strlen(base)], flags);
}

void    ft_putaddr(unsigned long addr, int count, char *base, t_flags *flags)
{
    if (count == 0)
        ft_putstr("0x", flags, -42);
    if (addr >= ft_strlen(base))
    {
        ft_putaddr(addr / ft_strlen(base), ++count, base, flags);
        ft_putaddr(addr % ft_strlen(base), ++count, base, flags);
    }
    else
        ft_putchar(base[addr % ft_strlen(base)], flags);
}

