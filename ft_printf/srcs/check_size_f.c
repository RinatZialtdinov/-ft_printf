/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:49:22 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:49:24 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	check_size_and_negative_float1(t_spec **el, int *size, t_float **numb)
{
	if ((*el)->plus == 1 || (*el)->negative == 1 || (*el)->spc == 1)
	{
		if ((*el)->negative == 1 && (*el)->plus == 1)
		{
			if (!((*el)->field > ft_intlen((*numb)->int_value) +
			(*el)->negative + (*el)->pre && (*el)->field != 0))
				(*size)++;
		}
		else
		{
			if (!((*el)->field > ft_intlen((*numb)->int_value) +
			(*el)->negative + (*el)->spc + (*el)->plus +
			(*el)->pre && (*el)->field != 0))
				(*size)++;
		}
	}
}

void	check_size_and_negative_float(t_spec **el, int *size, t_float **numb)
{
	int len_float;

	*size = 0;
	if ((*el)->pre != 0)
		len_float = ft_strlen((*numb)->float_val_str);
	else
		len_float = 0;
	check_size_and_negative_float1(el, size, numb);
	if (((*el)->pre == 0 && (*el)->lat == 1) &&
	(*el)->field < ft_intlen((*numb)->int_value) + (*el)->lat +
	(*el)->negative + (*el)->spc)
		(*size)++;
	if ((*el)->field > ft_intlen((*numb)->int_value) + len_float)
		*size = (*size) + (*el)->field;
	else if ((*el)->pre == -1)
		*size = (*size) + ft_intlen((*numb)->int_value) + len_float;
	else if ((*el)->pre == 0)
		*size = (*size) + ft_intlen((*numb)->int_value);
	else if ((*el)->pre != -1)
		*size = (*size) + ft_intlen((*numb)->int_value) + 1 + (*el)->pre;
}

void	va_arg_t_for_float(long double *num, va_list ap, t_spec *el)
{
	if (ft_strcmp(el->m, "l") == 0)
	{
		*num = va_arg(ap, long int);
	}
	else if (ft_strcmp(el->m, "L") == 0)
	{
		*num = va_arg(ap, long double);
	}
	else
	{
		*num = va_arg(ap, double);
	}
}
