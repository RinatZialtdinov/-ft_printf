/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:17 by damerica          #+#    #+#             */
/*   Updated: 2019/11/27 17:20:24 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_strjoin_one_elem(char *s1, char elem)
{
    char	*newstr;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
    newstr[i] = elem;
    newstr[i + 1] = '\0';
	return (newstr);
}

void check_precision(char **result, int *size, t_spec *elem, int number)
{
    int len;
    int i;
    int mod;

    i = 0;
    if (elem->precision == 0)
        return ;
    len = 0;
    if (elem->left == 0)
    {
        if ((*result)[0] == '+' || (*result)[0] == '-' || (*result)[0] == ' ')
        {
            i = 1;
            while ((*size) != i)
            {
                if (number != 0)
                {
                    mod = number % 10;
                    number = number / 10;
                    (*result)[(*size) - 1] = ((char) mod + 48);
                }
                else
                {
                    (*result)[(*size) - 1] = 48;
                }
                    (*size)--;
            }
        }
        else
        {
            i = 0;
            while ((*size) != i)
            {
                if (number != 0)
               {
                    mod = number % 10;
                    number = number / 10;
                    (*result)[(*size) - 1] = (char) mod + 48;
                }
                else
                {
                    (*result)[(*size) - 1] = 48;
                }
                (*size)--;
            }
        }  
    }
    else
    {
        if ((*result)[0] == '+' || (*result)[0] == '-' || (*result)[0] == ' ')
            i = 1;
        else
        {
            i = 0;
        }
        while ((*size) != i)
        {
            while (number != 0)
            {
                mod = number % 10;
                len = 10 * len + mod;
                number = number / 10;
                //(*result)[i] = ((char) mod + 48);
                //printf("len - %i\n", len);
            }
            if (len != 0)
            {
                mod = len % 10;
                len = len / 10;
                (*result)[i] = ((char) mod + 48);
            }
            else
            {
                (*result)[i] = ' ';
            }
            //printf("%s\n", (*result));
            i++;
        }
    }
    

}

void check_flag(char **result, int *size, t_spec *elem, int number)
{
    int i;

    i = 0;
    if (elem->minus == 1)
    {
        elem->left = 1;
    }
    else if(elem->nul == 1 && elem->precision == 0)
    {
        while (i != elem->field)
        {
            (*result)[i] = '0';
            i++;
        }
    }
    if (elem->plus == 1)
    {
        if (number >= 0)
            (*result)[0] = '+';
        else
            (*result)[0] = '-';
    }
    else if (elem->probel == 1)
    {
        if (number >= 0)
            (*result)[0] = ' ';
        else
            (*result)[0] = '-';     
    }
}
void write_int_elem(t_spec *elem, va_list ap)
{
    int size;
    int number;
    char *result;
    int i;
    int len;
    int mod;

    len = 0;
    i = 0;
    size = elem->field;
    result = (char *)malloc(sizeof(char) * (size + 1));
    number = va_arg(ap, int);
    check_flag(&result, &size, elem, number);
    if (elem->precision != 0)
        check_precision(&result, &size, elem, number);
    else
    {
        if (result[0] == '+' || result[0] == '-' || result[0] == ' ')
        {
            i = 1;
        }
        while (i != size)
        {
            while (number != 0)
            {
                mod = number % 10;
                len = 10 * len + mod;
                number = number / 10;
                //(*result)[i] = ((char) mod + 48);
                //printf("len - %i\n", len);
            }
            if (len != 0)
            {
                mod = len % 10;
                len = len / 10;
                result[i] = ((char) mod + 48);
            }
            else
            {
                result[i] = ' ';
            }
            i++;
        }
    }
    ft_putstr(result);
    //check_modif(&result, &size, elem);
}

void ft_create_str(t_spec *elem, va_list ap)
{
    if (elem->conv_type == 'd' || elem->conv_type == 'i' || elem->conv_type == 'u')
    {
        write_int_elem(elem, ap);
    }
    else if (elem->conv_type == 'o')
    {;}
    else if (elem->conv_type == 'x' || elem->conv_type == 'X')
    {;}
    else if (elem->conv_type == 'c')
    {;}
    else if (elem->conv_type == 's')
    {;}
    else if (elem->conv_type == 'p')
    {;}
    else if (elem->conv_type == 'f')
    {;}
}

void ft_create_elem(const char *format, int start, int end, va_list ap)
{
    t_spec *elem;
    int i;
    int size;
    char *str;

    size = 1;
    elem = (t_spec *)malloc(sizeof(t_spec));
    elem->minus = 0;
    elem->plus = 0;
    elem->probel = 0;
    elem->nul = 0;
    elem->field = 0;
    elem->precision = 0;
    elem->left = 0;
    i = 0;
    while (start <= end)
    {
        while (format[start] == '+' || format[start] == '-' || format[start] == ' ' || format[start] == '0')
        {
            if (format[start] == '+')
            {
                elem->plus = 1;
            }
            if (format[start] == '-')
            {
                elem->minus = 1;
            }
            if (format[start] == ' ')
            {
                elem->probel = 1;
            }
            if (format[start] == '0')
            {
                elem->nul = 1;
            }
            start++;
        }
        // ^^^ Не закончил данную часть ^^^
        if (format[start] == '#')
        {
            elem->conv_type = (char)malloc(sizeof(char) * 1);
            elem->conv_type = format[start + 1];
            break;
        }
        while (format[start] >= '0' && format[start] <= '9')
        {
            elem->field = 10 * elem->field + (format[start] - 48);
            start++;
        }
        if (format[start] == '.')
        {
            start++;
            while (format[start] >= '0' && format[start] <= '9')
            {
                elem->precision = 10 * elem->precision + (format[start] - 48);
                start++;
            }
        }
        if (format[start] == 'h' || format[start] == 'l' || format[start] == 'L')
        {
            elem->modif = (char *)malloc(sizeof(char) * 3);
            if (format[start + 1] == 'h' || format[start + 1] == 'l')
            {
                elem->modif[0] = format[start];
                elem->modif[1] = format[start + 1];
                start = start + 2;
            }
            else
            {
                elem->modif[0] = format[start];
                start++;
            }
        }
        // ^^^ Не закончил данную часть ^^^
        elem->conv_type = (char)malloc(sizeof(char) * 2);
        elem->conv_type = format[end];
        start++;
    }
    //printf("elem->conv-type %c\n", elem->conv_type);
    //printf("elem->flag |%s|\n", elem->flag);
    //printf("elem->precision %i\n", elem->precision);
    //printf("ele->field %i\n", elem->field);
    //printf("ele->modif %s\n", elem->modif);
    ft_create_str(elem, ap);
}


int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int k;

    i = 0;
    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            k = i;
            while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' 
            && format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && 
            format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && format[i] != 'f')
            {
                i++;
            }
            //printf("k = %c\n i = %c\n", format[k], format[i]);
            ft_create_elem(format, k + 1, i, ap);
        }
        else
        {
            ft_putchar(format[i]);
        }
        i++;
    }
    ft_putchar('\n');
    va_end(ap);
    return (i);
}

int main()
{
    int d1=123, d2=42, d3=1543;
    ft_printf("%06d\n", -123);
    printf("--------\n");
    printf("%06d\n", -123);
    return (0);
}