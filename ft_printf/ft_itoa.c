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
int	ft_intlen_it(long long n)
{
	int i;

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
char	*ft_itoa(long long n)
{
	long long	nbr;
	int			z;
	int			len;
	char		*str;

	nbr = n;
	z = 1;
	if (n < 0)
	{
		z = -1;
	}
	len = ft_intlen_it(n);
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
	return (str);
}
