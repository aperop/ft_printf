/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:22:40 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/30 20:04:37 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> 
# include "utils/libft.h"

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

int     ft_printf(const char *fmt, ...);
void	ft_parse(const char **fmt, t_flags *flags, t_args *arg, va_list ap);

#endif