/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:31:13 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:31:15 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_16_el_1(t_spec *el, char *numb, char **result, int *size)
{
	if (el->minus == 1)
		el->left = 1;
	if (el->pre > 0)
		check_pre_16(result, size, el, numb);
	else
	{
		if (el->left == 1)
			write_left_16(result, size, numb, el);
		else
			write_right_16(size, numb, result, el);
	}
}

void	write_16_el(t_spec *el, char *numb)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	check_size_16(&el, &size, &numb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while (i != size)
	{
		result[i] = ' ';
		i++;
	}
	write_16_el_1(el, numb, &result, &size);
	if (el->nul == 1 && el->pre <= 0)
		write_nul_or_spc(&result, '0', el);
	else
		write_nul_or_spc(&result, ' ', el);
	if (el->lat == 1)
		where_num_16(el, &result, numb);
	el->len = ft_strlen(result);
	ft_putstr(result);
	free(result);
}

void	convert_numb_1(t_spec *el, long long copy_numb, char *new_numb, int k)
{
	int mod;

	while (copy_numb > 0)
	{
		mod = copy_numb % 16;
		if (mod >= 10 && mod <= 15 && el->t == 'x')
			write_letter_a(mod, &new_numb, k);
		else if (mod >= 10 && mod <= 15 && el->t == 'X')
			write_letter_up_a(mod, &new_numb, k);
		else
			new_numb[k - 1] = mod + 48;
		copy_numb = copy_numb / 16;
		k--;
	}
}

int		value_k(long long numb)
{
	int k;

	k = 0;
	while (numb > 0)
	{
		numb = numb / 16;
		k++;
	}
	return (k);
}

void	convert_numb(t_spec *el, va_list ap)
{
	long long	numb;
	long long	copy_numb;
	char		*new_numb;
	int			k;

	va_arg_t(el, ap, &numb);
	copy_numb = numb;
	k = value_k(numb);
	if (copy_numb == 0)
	{
		el->it_nul = 1;
		new_numb = "0\0";
		write_16_el(el, new_numb);
		return ;
	}
	else
	{
		if (copy_numb == -1)
		{
			new_numb = (char *)malloc(sizeof(char) * (24));
			if (el->t == 'x')
				new_numb = ft_strcpy(new_numb, "ffffffffffffffff");
			else
				new_numb = ft_strcpy(new_numb, "FFFFFFFFFFFFFFFF");
		}
		else
		{
			new_numb = (char *)malloc(sizeof(char) * (k + 1));
			new_numb[k] = '\0';
		}
	}
	convert_numb_1(el, copy_numb, new_numb, k);
	write_16_el(el, new_numb);
	if (copy_numb != -1)
		free(new_numb);
}
