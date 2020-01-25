/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:32:08 by damerica          #+#    #+#             */
/*   Updated: 2020/01/25 18:32:10 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	check_size_8(t_spec **el, int *size, char **numb)
{
	*size = 0;
	if ((*el)->pre > (int)ft_strlen(*numb) - 1)
		(*size) = (*size) + (*el)->pre;
	else if ((*el)->pre != 0 && numb != 0)
    {
		(*size) = (*size) + (int)ft_strlen(*numb);
       // printf("%i\n", *size);
    }
    if ((*el)->field > (*size))
		(*size) = (*el)->field;
	if ((*el)->lat == 1 && (*el)->field <
	(*el)->pre + 2 && *numb[0] != '0')
    {
        //printf("!!!!%i\n", *size);
		(*size) = *size + 2;
    }
    if ((*el)->lat == 1 && (*el)->field != 0 && (*el)->field >
	(*el)->pre && (*el)->field < (int)ft_strlen(*numb) + 2)
	{
        //printf("!!!!%i\n", *size);	
        (*size) = (int)ft_strlen(*numb) + 1;
    }
    //printf("%i\n", *size);
}

void where_num_8(t_spec *el, char **result, char *numb)
{
    int i;
	int k;

	k = 0;
	i = 0;
	//printf("%s\n", *result);
	while ((*result)[i] == ' ' && (*result)[i] != '\0')
		i++;
	if (((*result)[i] == '\0' || numb[0] == '0') && (el->t != 'p'))
		return ;
    if (i == 0 && el->minus == 0)
	{
		//printf("fdfsa\n");
		(*result)[0] = '0';
    }
    if (el->minus == 1)
	{
		while ((*result)[k] != ' ')
			k++;
		k--;
		/*while (k != -1)
		{
			(*result)[k + 2] = (*result)[k];
			k--;
		}*/
		(*result)[0] = '0';
		//printf("fdfsa\n");
	}
	else
	{
		(*result)[i - 1] = '0';
	}
}

void	write_8_el(t_spec *el, char *numb)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	check_size_8(&el, &size, &numb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while (i != size)
	{
		result[i] = ' ';
		i++;
	}
	write_16_el_1(el, numb, &result, &size);
    //printf("%s\n", result);
	if (el->nul == 1 && el->pre <= 0)
		write_nul_or_spc(&result, '0', el);
	else
		write_nul_or_spc(&result, ' ', el);
	if (el->lat == 1)
		where_num_8(el, &result, numb);
	el->len = ft_strlen(result);
	ft_putstr(result);
	free(result);
}

void	convert_numb_8_1(long long copy_numb, char *new_numb, int k)
{
	int mod;

	while (copy_numb > 0)
	{
		mod = copy_numb % 8;
		new_numb[k - 1] = mod + 48;
		copy_numb = copy_numb / 8;
		k--;
	}
}

int		value_k_8(long long numb)
{
	int k;

	k = 0;
	while (numb > 0)
	{
		numb = numb / 8;
		k++;
	}
	return (k);
}

void	convert_numb_8(t_spec *el, va_list ap)
{
	long long	numb;
	long long	copy_numb;
	char		*new_numb;
	int			k;

	va_arg_t(el, ap, &numb);
	copy_numb = numb;
	k = value_k_8(numb);
	if (copy_numb == 0)
	{
		el->it_nul = 1;
		new_numb = "0\0";
		write_8_el(el, new_numb);
		return ;
	}
	else
	{
		new_numb = (char *)malloc(sizeof(char) * (k + 1));
		new_numb[k] = '\0';
	}
	convert_numb_8_1(copy_numb, new_numb, k);
	write_8_el(el, new_numb);
	free(new_numb);
}
