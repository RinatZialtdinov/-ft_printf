/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:27:04 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:27:05 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right(int *size, char *numb, char **result, t_spec *el)
{
	int i;
	int len_num;

	len_num = ft_strlen(numb);
	i = 0;
	while ((*size) != i)
	{
		if (len_num != 0 && (el->precision == -1 || numb[0] != '0'))
		{
			(*result)[(*size) - 1] = numb[len_num - 1];
			len_num--;
		}
		else if (el->nul == 1 && el->minus == 0 && el->precision <= 0)
		{
			if (el->plus == 1 && (*size) != 1)
				(*result)[(*size) - 1] = '0';
		}
		(*size)--;
	}
}

int		write_left(char **result, int *size, char *numb, t_spec *el)
{
	int len_num;
	int i;
	int i1;

	i1 = 0;
	i = 0;
	len_num = ft_strlen(numb);
	if (el->plus == 1 || el->negative == 1 || el->probel == 1)
		i = 1;
	while (i != (*size))
	{
		if (len_num != i1)
		{
			if (numb[0] == '0' && el->precision == -1)
				(*result)[i] = numb[i1];
			else if (numb[0] != '0' && el->precision == -1)
				(*result)[i] = numb[i1];
			i1++;
		}
		i++;
	}
	return (1);
}
