/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:00:32 by dmorrige          #+#    #+#             */
/*   Updated: 2020/01/26 15:02:17 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void write_c_elem(t_spec *elem, va_list ap)
{
	char *result;
	char a;
	char b;

	a = (unsigned char)va_arg(ap, int);
	b = ' ';
	if (elem->field)
	{
		result = (char *)malloc(elem->field);
		ft_memset(result, b, elem->field);
		if (elem->minus)
			result[0] = a;
		else
			result[elem->field - 1] = a;
		write(1, result, elem->field);
		elem->len = elem->field;
		free(result);
	} 
	else 
	{
	ft_putchar(a);
	elem->len = 1;
	}

}