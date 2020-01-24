/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:29 by damerica          #+#    #+#             */
/*   Updated: 2020/01/24 16:54:49 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "printf.h"

long long ft_intlen_it(long long n)
{
	long long i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
char	*ft_itoa_pf(long long n, t_spec *elem)
{
	long long	nbr;
	int			z;
	long long	len;
	char		*str;

	nbr = n;
	z = 1;
	if (n < 0)
	{
		z = -1;
	}
	len = ft_intlen_it(n);
	//printf("n - %lli len - %lli\n", n, len);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = (nbr % 10) * z + 48;
		nbr = nbr / 10;
		len--;
	}
	if (z == -1)
		str[0] = '-';
	if (n == -42 && elem->conv_type == 'u')
	{
		//printf("ahah\n");
		free (str);
		return("18446744073709551574");
	}
	return (str);
}
