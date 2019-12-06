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

void write_right(int *size, int number, char **result, t_spec *elem)
{
    int mod;
    int i;
    int count;

    count = ft_intlen(number);
    i = 0;
    //printf("hey\n");
    while ((*size) != i)
    {
        if (number != 0)
        {
            mod = number % 10;
            number = number / 10;
            (*result)[(*size) - 1] = (char) mod + 48;
        }
        else if (elem->nul == 1 && elem->minus == 0 && elem->precision == 0)
        {
            if (elem->plus == 1 && (*size) != 1)
                (*result)[(*size) - 1] = 48;
            count++;
        }
        (*size)--;
    }
}

int write_left(char **result, int *size, int number, t_spec *elem)
{
    int mod;
    int len;
    int i;

    i = 0;
    len = 0;
    //printf("y \n");
     //printf("res - |%s|\n", *result);
    if (elem->plus == 1 || elem->negative == 1 || elem->probel == 0)
    {
        i = 1;
    }
    //if (elem->minus == 1)
    //{
        while (i != (*size))
        {
            while (number != 0)
            {
                mod = number % 10;
                len = 10 * len + mod;
                number = number / 10;
                    //(*result)[i] = ((char) mod + 48);
                    //printf("len - %i\n", len);
            }
            //printf("len - %i\n", len);
            if (len != 0)
            {
                //printf("yay\n");
                mod = len % 10;
                len = len / 10;
                (*result)[i] = ((char) mod + 48);
            }
            i++;
        }
        //printf("res - %s\n", *result);
        return (1);
    //}
    //printf("res - %s\n", *result);
    //return (0);
}

void write_right_prec(int *size, int number, char **result, t_spec *elem)
{
    int mod;
    int i;
    int count;
    int copy_precision;

    copy_precision = elem->precision;
    //printf("hieA\n");
    count = ft_intlen(number);
    i = 0;
    while ((*size) != i)
    {
        if (number != 0)
        {
            mod = number % 10;
            number = number / 10;
            (*result)[(*size) - 1] = (char) mod + 48;
            copy_precision--;
        }
        else if (copy_precision != 0)
        {
            (*result)[(*size) - 1] = '0';
            copy_precision--;
        }
        (*size)--;

    }
    //printf("result - |%s|\n", *result);
}

void write_left_prec(char **result, int *size, int number, t_spec *elem)
{
    int mod;
    int len;
    int i;
    int len_num;
    int copy_precision;

    copy_precision = elem->precision;
    //printf("%i\n", copy_precision);
    len_num = ft_intlen(number);
    //printf("%i\n", len_num);
    //printf("asdasd%+-06.4d\n", -123);
    i = 0;
    len = 0;
    if (elem->plus == 1 || elem->negative == 1 || elem->probel == 1)
    {
        i = 1;
    }
    while (i != (*size))
    {
        while (number != 0)
        {
            mod = number % 10;
            len = 10 * len + mod;
            number = number / 10;
        }
        if (copy_precision > len_num)
        {
            copy_precision--;
            (*result)[i] = '0';
            //printf("hieA\n");
        }
        else
        {
            if (len != 0)
            {
                mod = len % 10;
                len = len / 10;
                (*result)[i] = ((char) mod + 48);
                //printf("hieA\n");
            }
        }
        i++;
    }
    //printf("%s\n", (*result));
}

void check_precision(char **result, int *size, t_spec *elem, int number)
{
    int i;
    int mod;
    int count;

    count = ft_intlen(number);
    i = 0;
    if (elem->precision == 0)
        return ;
    if (elem->left == 1)
    {
        write_left_prec(result, size, number, elem);
    }
    else
    {
        write_right_prec(size, number, result, elem);
    }
    

}

void where_num(char **result, t_spec *elem)
{
    int i;
    //printf("==%s\n", *result);
    i = 0;
    while ((*result)[i] == ' ')
    {
        i++;
    }
    i--;
    if (i == 0)
    {
        if (elem->negative == 1)
            (*result)[i] = '-';
        else if (elem->plus == 1)
        {
            (*result)[i] = '+';
        }
        else if (elem->probel == 1)
        {
            (*result)[i] = ' ';
        }
        
    }
    else
    {
        if (elem->negative == 1)
            (*result)[i] = '-';
        else if (elem->plus == 1)
        {
            (*result)[i] = '+';
        }
        else if (elem->probel == 1)
        {
            (*result)[i] = ' ';
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
        ;
    }
    else if (elem->probel == 1)
    {
        if (number >= 0)
            (*result)[0] = ' ';
        else
            (*result)[0] = '-';     
    }
    //printf("result - %s\n", (*result));
}

void check_size_and_negative(t_spec **elem, int *size, int *number)
{
    *size = 0;
    if ((*elem)->plus == 1 || (*number) < 0)
    {
        if ((*number) < 0)
        {
            (*elem)->negative = 1;
            *number = - (*number);
        }
        (*size)++;
    }
    if ((*elem)->precision > ft_intlen(*number))
    {
        (*size) = (*size) + (*elem)->precision;
    }
    else
    {
        (*size) = (*size) + ft_intlen(*number);
    }
    if ((*elem)->field > (*size))
    {
        (*size) = (*elem)->field;
    }
}

void write_nul_or_probel(char **result, char set, t_spec *elem)
{
    int i;
    int len;

    len = 0;
    while ((*result)[len + 1] != '\0')
    {
        len++;
    }
    //printf("len = %i\n", len);
    i = 0;
    //printf("res - %c\n", (*result)[0]);
    if (elem->plus == 1 || elem->negative == 1 || elem->probel == 1)
        i++;
    while (i != len)
    {
        if ((*result)[i] >= '0' && (*result)[i] <= '9')
            return ;
        else
        {
            (*result)[i] = set;
        }
        i++;
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
    char sign;

    len = 0;
    i = 0;
    number = va_arg(ap, int);
    check_size_and_negative(&elem, &size, &number);
    //printf("%i\n", size);
    result = (char *)malloc(sizeof(char) * (size + 1));
    int z = 0 ;
    result[size] = '\0';
    while (z != size)
    {
        result[z] = ' ';
        z++;
    }
    if (elem->minus == 1)
    {
        elem->left = 1;
    }
    //printf("elem - %i\n", elem->precision);
    if (elem->precision != 0)
    {
        //printf("hi everye=one\n");
        check_precision(&result, &size, elem, number);
        //printf("hi everye==one\n");
    }
    else
    {
        if (elem->left == 1)
        {
            //printf("hi everye=one\n");
            write_left(&result, &size, number, elem);
        }
        else
        {
            //printf("hi everye=one\n");
            write_right(&size, number, &result, elem);
        }
    }
    if (elem->nul == 1 && elem->precision == 0)
    {
        //printf("hi everye=one\n");
        //printf("elem - %i\n", elem->precision);
        write_nul_or_probel(&result, '0', elem);
        //printf("hi everye=one\n");
    }
    else
    {
        //printf("hi everye=one\n");
        write_nul_or_probel(&result, ' ', elem);
    }
    //printf("result - %s\n", result);

    if ((elem->negative == 1 || elem->plus == 1) || (elem->probel == 1 && elem->precision == 0))
        where_num(&result, elem);
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

void parametres(t_spec **elem)
{
    (*elem) = (t_spec *)malloc(sizeof(t_spec));
    (*elem)->minus = 0;
    (*elem)->plus = 0;
    (*elem)->probel = 0;
    (*elem)->nul = 0;
    (*elem)->field = 0;
    (*elem)->precision = 0;
    (*elem)->left = 0;
    (*elem)->negative = 0;
}

void ft_create_elem(const char *format, int start, int end, va_list ap)
{
    t_spec *elem;
    int i;
    int size;
    char *str;

    size = 1;
    parametres(&elem);
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
    va_end(ap);
    return (i);
}

int main()
{
    int d1=123, d2=42, d3=1543;
    ft_printf("%0.6d\n", 2147483647);
    printf("%0.6d\n", 2147483647);
    return (0);
}