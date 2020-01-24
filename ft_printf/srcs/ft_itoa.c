/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:29 by damerica          #+#    #+#             */
/*   Updated: 2019/09/18 18:21:07 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/printf.h"

long long	ft_intlen_it(long long n)
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

char		*ft_itoa(long long n, t_spec *el)
{
	int			z;
	long long	len;
	char		*str;

	z = 1;
	if (n < 0)
		z = -1;
	len = ft_intlen_it(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (n == -42 && el->t == 'u')
	{
		free(str);
		return ("18446744073709551574");
	}
	while (len >= 0)
	{
		str[len] = (n % 10) * z + 48;
		n = n / 10;
		len--;
	}
	if (z == -1)
		str[0] = '-';
	return (str);
}
