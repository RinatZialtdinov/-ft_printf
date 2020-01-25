/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:27:54 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:27:56 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	check_size_and_negative_int(t_spec **el, int *size, long long *numb)
{
	*size = 0;
	if (((*el)->plus == 1 || (*numb) < 0 ||
	(*el)->spc == 1) && ((*el)->t != 'u'))
	{
		if ((*numb) < 0)
		{
			(*el)->negative = 1;
			*numb = -(*numb);
		}
		(*size)++;
	}
	if ((*el)->pre > 0 && (*el)->pre > ft_intlen(*numb))
		(*size) = (*size) + (*el)->pre;
	else if ((*el)->pre != 0 || *numb != 0)
		(*size) = (*size) + ft_intlen(*numb);
	if ((*el)->field != 0 && (*el)->field > (*size))
		(*size) = (*el)->field;
}

void	write_int_el_1(t_spec *el, char **result, int size, char *str_numb)
{
	int z;

	z = -1;
	while (++z != size)
		(*result)[z] = ' ';
	if (el->pre > 0)
		check_pre(result, &size, el, str_numb);
	else
	{
		if (el->minus == 1)
			write_left(result, &size, str_numb, el);
		else
			write_right(&size, str_numb, result, el);
	}
	if (el->nul == 1 && el->pre <= 0)
		write_nul_or_spc(result, '0', el);
}

void	write_int_el(t_spec *el, va_list ap)
{
	int			size;
	long long	numb;
	char		*result;
	char		*str_numb;
	int			z;

	z = -1;
	va_arg_t(el, ap, &numb);
	if (numb == 0)
		el->it_nul = 1;
	check_size_and_negative_int(&el, &size, &numb);
	str_numb = ft_itoa(numb, el);
	if (ft_strcmp(str_numb, "18446744073709551574") == 0)
		size = 20;
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	write_int_el_1(el, &result, size, str_numb);
	if ((el->negative == 1 || el->plus == 1)
	|| (el->spc == 1 && el->pre == 0))
		where_num(&result, el);
	el->len = ft_strlen(result);
	ft_putstr(result);
	free(result);
	//free(str_numb);
}
