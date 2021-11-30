#include "ft_printf.h"

static void ft_init(t_flags *flags, t_args *arg)
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
    flags->printlen = 0;
    arg->symbol = 0;
    arg->str = NULL;
    arg->integer = 0;
    arg->base = NULL;
}

void	ft_parse(const char **fmt, t_flags *flags, t_args *arg, va_list ap)
{
    ft_init(flags, arg);
    ft_flags(fmt, flags, ap);
}