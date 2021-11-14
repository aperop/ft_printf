/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:56:08 by dhawkgir          #+#    #+#             */
/*   Updated: 2021/10/29 15:54:22 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция toupper возвращает соответствующий верхнему регистру
эквивалент символа c, если c — это буква.
В противном случае c возвращается неизмененным.
*/
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}
