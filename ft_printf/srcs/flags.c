/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:12:40 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:12:43 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_create_el_4(const char *format, int *start, t_spec **el)
{
	if (format[*start] == 'h' || format[*start] == 'l' || format[*start] == 'L')
	{
		if (format[(*start) + 1] == 'h' || format[(*start) + 1] == 'l')
		{
			(*el)->m[0] = format[*start];
			(*el)->m[1] = format[(*start) + 1];
			*start = *start + 2;
		}
		else
		{
			(*el)->m[0] = format[*start];
			(*start)++;
		}
	}
}

void	ft_create_el_3(const char *format, int *start, t_spec **el, va_list ap)
{
	while ((format[*start] >= '0' && format[*start] <= '9')
	|| format[*start] == '*')
	{
		if (format[*start] == '*')
		{
			(*el)->field = va_arg(ap, int);
			break ;
		}
		else
			(*el)->field = 10 * (*el)->field + (format[*start] - 48);
		(*start)++;
	}
}

void	ft_create_el_2(const char *format, int *start, t_spec **el, va_list ap)
{
	if (format[*start] == '.')
	{
		(*el)->precision = 0;
		(*start)++;
		while ((format[*start] >= '0' && format[*start] <= '9')
		|| format[*start] == '*')
		{
			if (format[*start] == '*')
			{
				(*el)->precision = va_arg(ap, int);
				break ;
			}
			else
				(*el)->precision = 10 * (*el)->precision
				+ (format[*start] - 48);
			(*start)++;
		}
	}
}

void	ft_create_el_1(const char *format, int *start, t_spec **el)
{
	while (format[*start] == '+' || format[*start] == '-'
	|| format[*start] == ' ' || format[*start] == '0')
	{
		if (format[*start] == '+')
			(*el)->plus = 1;
		if (format[*start] == '-')
			(*el)->minus = 1;
		if (format[*start] == ' ')
			(*el)->probel = 1;
		if (format[*start] == '0')
			(*el)->nul = 1;
		(*start)++;
	}
	if (format[*start] == '#')
		(*el)->lat = 1;
}

void	ft_create_el_5(int *result, t_spec **el)
{
	*result = (*el)->len;
	free((*el)->m);
	free(*el);
}
