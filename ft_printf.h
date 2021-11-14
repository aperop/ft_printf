/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:22:40 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/11/14 13:52:39 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> 
# include "utils/libft.h"

typedef struct	s_specifier
{
	int	flags;
	int	width;
	int	prec;
	int lenght;
	int	type;
	
}				t_specifier;


#endif