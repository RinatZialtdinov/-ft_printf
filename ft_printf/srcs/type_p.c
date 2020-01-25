/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file17.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:12:11 by damerica          #+#    #+#             */
/*   Updated: 2020/01/24 18:12:13 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_point_el_1(long long copy_numb, char *new_numb, int k)
{
	int mod;

	while (copy_numb > 0)
	{
		mod = copy_numb % 16;
		if (mod >= 10 && mod <= 15)
		{
			write_letter_a(mod, &new_numb, k);
		}
		else
		{
			new_numb[k - 1] = mod + 48;
		}
		copy_numb = copy_numb / 16;
		k--;
	}
}

void	write_point_el(t_spec *el, va_list ap)
{
	long long	number;
	long long	copy_number;
	char		*new_number;
	int			k;

	el->lat = 1;
	number = va_arg(ap, unsigned long long);
	copy_number = number;
	k = value_k(number);
	if (copy_number == 0)
	{
		el->it_nul = 1;
		new_number = "0\0";
		write_16_el(el, new_number);
		return ;
	}
	else
	{
		new_number = (char *)malloc(sizeof(char) * (k + 1));
		new_number[k] = '\0';
	}
	write_point_el_1(copy_number, new_number, k);
	write_16_el(el, new_number);
	free(new_number);
}
