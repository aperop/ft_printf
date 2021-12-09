#include "ft_printf.h"

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