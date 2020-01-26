/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:57:20 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:57:21 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	va_arg_t(t_spec *el, va_list ap, long long *numb)
{
	if (ft_strcmp(el->m, "h") == 0 && (el->t == 'i' || el->t == 'd'))
		*numb = (short)va_arg(ap, int);
	else if (ft_strcmp(el->m, "h") == 0 && (el->t == 'o' ||
	el->t == 'u' || el->t == 'x' || el->t == 'X'))
		*numb = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(el->m, "hh") == 0 && (el->t == 'i' || el->t == 'd'))
		*numb = (char)va_arg(ap, int);
	else if (ft_strcmp(el->m, "hh") == 0 && (el->t == 'o' ||
	el->t == 'u' || el->t == 'x' || el->t == 'X'))
		*numb = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(el->m, "l") == 0 && (el->t == 'i' || el->t == 'd'))
		*numb = va_arg(ap, long int);
	else if (ft_strcmp(el->m, "l") == 0 && (el->t == 'o' ||
	el->t == 'u' || el->t == 'x' || el->t == 'X'))
		*numb = va_arg(ap, unsigned long);
	else if (ft_strcmp(el->m, "ll") == 0 && (el->t == 'i' || el->t == 'd'))
		*numb = va_arg(ap, long long);
	else if (ft_strcmp(el->m, "ll") == 0 && (el->t == 'o' ||
	el->t == 'u' || el->t == 'x' || el->t == 'X'))
		*numb = va_arg(ap, unsigned long long int);
	else if (el->t == 'x' || el->t == 'X' ||
	el->t == 'o' || el->t == 'u')
		*numb = (unsigned int)va_arg(ap, int);
	else
		*numb = va_arg(ap, int);
}

void	where_num(char **result, t_spec *el)
{
	int i;

	i = 0;
	while ((*result)[i] == ' ' && (*result)[i] != '\0')
		i++;
	if (i == (int)ft_strlen(*result) && el->minus == 1)
		i = 1;
	i--;
	if (i == 0)
	{
		if (el->negative == 1)
			(*result)[i] = '-';
		else if (el->plus == 1)
			(*result)[i] = '+';
		else if (el->spc == 1)
			(*result)[i] = ' ';
	}
	if (el->negative == 1)
		(*result)[i] = '-';
	else if (el->plus == 1)
		(*result)[i] = '+';
	else if (el->spc == 1)
		(*result)[i] = ' ';
}

void	write_nul_or_spc(char **result, char set, t_spec *el)
{
	int i;
	int len;

	len = 0;
	while ((*result)[len + 1] != '\0')
		len++;
	i = 0;
	if (el->plus == 1 || el->negative == 1 || el->spc == 1)
		i++;
	while (i < len)
	{
		if (((*result)[i] >= '0' && (*result)[i] <= '9') ||
		((*result)[i] >= 'a' && (*result)[i] <= 'f') ||
		((*result)[i] >= 'A' && (*result)[i] <= 'F'))
			return ;
		else
			(*result)[i] = set;
		i++;
	}
}
