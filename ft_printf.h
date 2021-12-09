/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:22:40 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/12/09 17:08:29 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct  s_flags
{
	char    convertation;
	
	int     align;
	int     zero;
	int     dot;
	
	int     hash;
	int     space;
	int     plus;

	int     precision;
	int     width;
	int     arglen;
	int     printlen;
}               t_flags;

typedef struct  s_args
{
	char        symbol;
	char        *str;
	long long   integer;
	char        *base;
}               t_args;

void 	ft_init(t_flags *flags, t_args *arg);
int 	ft_nbr_digit(long long n, char *base);
int 	ft_nbr_digit_unsigned(unsigned long n, char *base);
int 	ft_search(char c, char *s);
int 	ft_width(const char **fmt);
void    ft_processor(t_flags *flags, t_args *arg);
void    ft_putnbr_unsigned(unsigned int number, char *base, t_flags *flags);
void    ft_putaddr(unsigned long addr, int count, char *base, t_flags *flags);
void	ft_putchar(char c, t_flags *flags);
void    ft_putstr(char *str, t_flags *flags, int n);
void	ft_putnbr(int n, t_flags *flags);
size_t	ft_strlen(const char *s);
void    ft_print(t_flags *flags, t_args *arg);
int     ft_printf(const char *fmt, ...);
void	ft_parse(const char **fmt, t_flags *flags, t_args *arg, va_list ap);

#endif