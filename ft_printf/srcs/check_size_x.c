/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:53:37 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:53:38 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_letter_up_a(int mod, char **new_numb, int k)
{
	if (mod == 10)
		(*new_numb)[k - 1] = 'A';
	else if (mod == 11)
		(*new_numb)[k - 1] = 'B';
	else if (mod == 12)
		(*new_numb)[k - 1] = 'C';
	else if (mod == 13)
		(*new_numb)[k - 1] = 'D';
	else if (mod == 14)
		(*new_numb)[k - 1] = 'E';
	else if (mod == 15)
		(*new_numb)[k - 1] = 'F';
}

void	write_letter_a(int mod, char **new_numb, int k)
{
	if (mod == 10)
		(*new_numb)[k - 1] = 'a';
	else if (mod == 11)
		(*new_numb)[k - 1] = 'b';
	else if (mod == 12)
		(*new_numb)[k - 1] = 'c';
	else if (mod == 13)
		(*new_numb)[k - 1] = 'd';
	else if (mod == 14)
		(*new_numb)[k - 1] = 'e';
	else if (mod == 15)
		(*new_numb)[k - 1] = 'f';
}

void	check_size_16(t_spec **el, int *size, char **numb)
{
	*size = 0;
	if ((*el)->pre > (int)ft_strlen(*numb) - 1)
		(*size) = (*size) + (*el)->pre;
	else if ((*el)->pre != 0 && numb != 0)
		(*size) = (*size) + (int)ft_strlen(*numb);
	if ((*el)->field > (*size))
		(*size) = (*el)->field;
	if ((*el)->lat == 1 && (*el)->field <
	(*el)->pre + 2 && *numb[0] != '0')
		(*size) = *size + 2;
	if ((*el)->lat == 1 && (*el)->field != 0 && (*el)->field >
	(*el)->pre && (*el)->field < (int)ft_strlen(*numb) + 2)
		(*size) = (int)ft_strlen(*numb) + 2;
	if ((*el)->t == 'p' && (*el)->field == 0 && *size == 1)
		*size = 3;
}
