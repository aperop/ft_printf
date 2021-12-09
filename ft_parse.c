#include "ft_printf.h"

static void ft_flags(const char **fmt, t_flags *flags)
{
    while (**fmt && (ft_search(*fmt[0], "+ #-0") || ft_search(*fmt[0], "0123456789")))
    {
        if (**fmt == '+' && (*fmt)++)
            flags->plus = 1;
        else if (**fmt == ' ' && (*fmt)++)
            flags->space = 1;
        else if (**fmt == '#' && (*fmt)++)
            flags->hash = 1;
        else if (**fmt == '-')
        {
            flags->align = 1;
            while ((**fmt) == '-')
                (*fmt)++;
            flags->width = ft_width(fmt);
        }
        else if (**fmt == '0')
        {
            flags->zero = 1;
            flags->width = ft_width(fmt);
        }
        else if (**fmt && (**fmt) >= '0' && (**fmt) <= '9')
            flags->width = ft_width(fmt);
    }
}

static void ft_flags_end(const char **fmt, t_flags *flags)
{
    if (**fmt == '.' && (**fmt))
    {
        flags->dot = 1;
        (*fmt)++;
        flags->precision = ft_width(fmt);
    }
    if ((**fmt) && ft_search(*fmt[0], "cspdiuxX%"))
    {
        flags->convertation = *fmt[0];
        (*fmt)++;
    }
    
}

static void ft_arglen(t_flags *flags, t_args *arg)
{   
    if (ft_search(flags->convertation, "diuxXp"))
        if(flags->convertation == 'p' && (long)arg->integer < 0)
            flags->arglen = ft_nbr_digit_unsigned(arg->integer, arg->base);
        else if (arg->integer < 0)
            flags->arglen = ft_nbr_digit((-1) * arg->integer, arg->base);
        else
            flags->arglen = ft_nbr_digit(arg->integer, arg->base);
    else if (flags->convertation == 's')
        flags->arglen = ft_strlen(arg->str);
    else
        flags->arglen = 1;
}

static void ft_arg(t_flags *flags, t_args *arg, va_list ap)
{
    if (ft_search(flags->convertation, "di"))
        arg->integer = va_arg(ap, int);
    else if (ft_search(flags->convertation, "uxX"))
        arg->integer = va_arg(ap, unsigned int);
    else if (ft_search(flags->convertation, "p"))
        arg->integer = va_arg(ap, unsigned long);
    else if (ft_search(flags->convertation, "c"))
        arg->symbol = va_arg(ap, int);
    else if (ft_search(flags->convertation, "%"))
        arg->symbol = '%';
    else
        arg->str = va_arg(ap, char *);
    if (arg->str == NULL && flags->convertation == 's')
        arg->str = "(null)";
}

void    ft_parse(const char **fmt, t_flags *flags, t_args *arg, va_list ap)
{
    ft_init(flags, arg);
    ft_flags(fmt, flags);
    ft_flags_end(fmt, flags);
    ft_arg(flags, arg, ap);
    if (ft_search(flags->convertation, "diu"))
        arg->base = "0123456789";
    else if (ft_search(flags->convertation, "px"))
        arg->base = "0123456789abcdef";
    else if (flags->convertation == 'X')
        arg->base = "0123456789ABCDEF";
    ft_arglen(flags, arg);
    ft_processor(flags, arg);
}