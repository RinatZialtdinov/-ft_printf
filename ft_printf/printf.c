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

void va_arg_type(t_spec *elem, va_list ap, long long *number)
{
    //printf("ya tut\n");
    if (ft_strcmp(elem->modif, "h") == 0 && (elem->conv_type == 'i' || elem->conv_type == 'd'))
    {
        //printf("yayt\n");
        *number = (short)va_arg(ap, int);
    }
    else if (ft_strcmp(elem->modif, "h") == 0 && (elem->conv_type == 'o' || elem->conv_type == 'u' || 
    elem->conv_type == 'x' || elem->conv_type == 'X'))
    {
        *number = (unsigned short)va_arg(ap, int);    
    }
    else if (ft_strcmp(elem->modif, "hh") == 0 && (elem->conv_type == 'i' || elem->conv_type == 'd'))
    {
        *number = (char) va_arg(ap, int);
    }
    else if (ft_strcmp(elem->modif, "hh") == 0 && (elem->conv_type == 'o' || elem->conv_type == 'u' || 
    elem->conv_type == 'x' || elem->conv_type == 'X'))
    {
        *number = (unsigned char) va_arg(ap, int);    
    }
    else if (ft_strcmp(elem->modif, "l") == 0 && (elem->conv_type == 'i' || elem->conv_type == 'd'))
    {
        *number = va_arg(ap, long int);
    }
    else if (ft_strcmp(elem->modif, "l") == 0 && (elem->conv_type == 'o' || elem->conv_type == 'u' || 
    elem->conv_type == 'x' || elem->conv_type == 'X'))
    {
        *number = va_arg(ap, unsigned long);    
    }
    else if (ft_strcmp(elem->modif, "ll") == 0 && (elem->conv_type == 'i' || elem->conv_type == 'd'))
    {
        *number = va_arg(ap, long long);
    }
    else if (ft_strcmp(elem->modif, "ll") == 0 && (elem->conv_type == 'o' || elem->conv_type == 'u' || 
    elem->conv_type == 'x' || elem->conv_type == 'X'))
    {
        *number = va_arg(ap, unsigned long long int);    
    }
    else if (ft_strcmp(elem->modif, "L") == 0 && elem->conv_type == 'f')
    {
        *number = va_arg(ap, double);
    }
    else if (elem->conv_type == 'x' || elem->conv_type == 'X' || elem->conv_type == 'o' || elem->conv_type == 'u')
    {
        *number = (unsigned int) va_arg(ap, int);
        //printf("%lli\n", *number);
    }
    else
    {
        *number = va_arg(ap, int);
        //printf("num - %i\n", *number);
    }
    
    //printf("ya tut\n");
}

void check_size_str(t_spec **elem, int *size, char **str)
{
    *size = ft_strlen(*str);
    if ((*elem)->field > (*size))
    {
        (*size) = (*elem)->field;
    }
    else if ((*elem)->precision > 0 && (*elem)->field != 0)
    {
        (*size) = (*elem)->field;
    }
    else if ((*elem)->precision != 0 && (*elem)->precision < (int) ft_strlen(*str))
    {
        (*size) = (*elem)->precision;
    }
    
}

void write_right_prec_str(int *size, char *str, char **result, t_spec *elem)
{
    int copy_precision_str;
    int len_num;
    int i;

    i = 0;
    len_num = ft_strlen(str);
    copy_precision_str = elem->precision;
    //printf("++%i\n", len_num);
    while ((*size) != 0)
    {
        if (len_num != 0 && copy_precision_str != 0)
        {
            (*result)[(*size) - 1] = str[-1 + copy_precision_str];
            copy_precision_str--;
            len_num--;
        }
        (*size)--;
    }
}

void write_left_prec_str(char **result, int *size, char *str, t_spec *elem)
{
    int i;
    int copy_precision_str;
    int len_str;
    int i1;

    i1 = 0;
    len_str = ft_strlen(str);
    copy_precision_str = elem->precision;
    i = 0;
    while (i != (*size))
    {
        if (copy_precision_str != 0 && len_str != 0)
        {
            (*result)[i] = str[i];
            copy_precision_str--;
            len_str--;
        }
        i++;
    }
}

void check_precision_str(char **result, int *size, t_spec *elem, char *str)
{
    if (elem->left == 1)
    {
        //printf("+=%s|\n", *result);
        write_left_prec_str(result, size, str, elem);
    }
    else
    {
        //printf("ds\n");
        write_right_prec_str(size, str, result, elem);
    }
}

void write_right_str(int *size, char *str, char **result)
{
    int i;
    int len_int;

    len_int = ft_strlen(str);
    i = 0;
    //printf("size - %i\n", len_int);
    while ((*size) != i)
    {
        if (len_int > 0)
        {
            (*result)[(*size) - 1] = str[len_int - 1];
            len_int--;
        }
        (*size)--;
    }
}

void write_left_str(char **result, int *size, char *str)
{
    int i;
    int i1;
    int len_num;

    //printf("y \n");
    len_num = ft_strlen(str);
    i1 = 0;
    i = 0;
    while (i != (*size))
    {
        if (len_num != i1)
        {
            (*result)[i] = str[i1];
            i1++;
        }
        i++;
    }
}

void write_str_elem(t_spec *elem, va_list ap)
{
    char *result;
    char *str;
    int size;
    int i;

    i = 0;
    str = va_arg(ap, char *);
    //printf("str - %s\n", str);
    check_size_str(&elem, &size, &str);
    //printf("size - %i\n", size);
    result = (char *)malloc(sizeof(char) * (size + 1));
    result[size] = '\0';
    while (i != size)
    {
        result[i] = ' ';
        i++;
    }
    if (elem->minus == 1)
    {
        elem->left = 1;
    }
    if (elem->precision != 0)
    {
        //printf("size - %i\n", size);
        check_precision_str(&result, &size, elem, str);
    }
    else 
    {
        if (elem->left == 1)
        {
            write_left_str(&result, &size, str);
        }
        else
        {
            write_right_str(&size, str, &result);
        }
    }
    elem->len = ft_strlen(result);
    ft_putstr(result);
}








void write_nul_or_probel(char **result, char set, t_spec *elem);

void write_letter_A(int mod, char **new_number, int k)
{
    if (mod == 10)
        (*new_number)[k - 1] = 'A';
    else if (mod == 11)
        (*new_number)[k - 1] = 'B';
    else if (mod == 12)
        (*new_number)[k - 1] = 'C';
    else if (mod == 13)
        (*new_number)[k - 1] = 'D';
    else if (mod == 14)
        (*new_number)[k - 1] = 'E';
    else if (mod == 15)
        (*new_number)[k - 1] = 'F';
}

void write_letter_a(int mod, char **new_number, int k)
{
    if (mod == 10)
        (*new_number)[k - 1] = 'a';
    else if (mod == 11)
        (*new_number)[k - 1] = 'b';
    else if (mod == 12)
        (*new_number)[k - 1] = 'c';
    else if (mod == 13)
        (*new_number)[k - 1] = 'd';
    else if (mod == 14)
        (*new_number)[k - 1] = 'e';
    else if (mod == 15)
        (*new_number)[k - 1] = 'f';
}

void check_size_16(t_spec **elem, int *size, char **number)
{
    *size = 0;
    if ((*elem)->precision > (int)ft_strlen(*number) - 1 )
    {
        (*size) = (*size) + (*elem)->precision;
    }
    else
    {
        (*size) = (*size) + ft_strlen(*number);
    }
    if ((*elem)->field > (*size))
    {
        (*size) = (*elem)->field;
    }
}

void write_right_prec_16(int *size, char *number, char **result, t_spec *elem)
{
    int copy_precision_16;
    int len_num;
    int i;

    i = 0;
    len_num = ft_strlen(number);
    copy_precision_16 = elem->precision;
    //printf("++%i\n%i\n", len_num, copy_precision_16);
    while ((*size) != i)
    {
        if (len_num != 0)
        {
            (*result)[(*size) - 1] = number[len_num - 1];
            copy_precision_16--;
            len_num--;
        }
        else if (copy_precision_16 > 0)
        {
            //printf("++%i\n", len_num);
            (*result)[(*size) - 1] = '0';
            copy_precision_16--;
        }
        (*size)--;
    }

}

void write_left_prec_16(char **result, int *size, char *number, t_spec *elem)
{
    int i;
    int copy_precision_16;
    int len_num;
    int i1;

    i1 = 0;
    len_num = ft_strlen(number);
    copy_precision_16 = elem->precision;
    i = 0;
    while (i != (*size))
    {
        if (copy_precision_16 > len_num)
        {
            copy_precision_16--;
            (*result)[i] = '0';
        }
        else
        {
            if (i1 != len_num)
            {
                (*result)[i] = number[i1];
                i1++;
            }
        }
        i++;
    }
}

void check_precision_16(char **result, int *size, t_spec *elem, char *number)
{
    if (elem->left == 1)
    {
        //printf("+=%s|\n", *result);
        write_left_prec_16(result, size, number, elem);
    }
    else
    {
        write_right_prec_16(size, number, result, elem);
    }
}

void write_right_16(int *size, char *number, char **result, t_spec *elem)
{
    int i;
    int len_int;

    len_int = ft_strlen(number);
    i = 0;
    while ((*size) != i)
    {
        //printf("hi\n");
        if (len_int != 0)
        {
            //printf("size - %c\n", number[len_int - 1]);
            (*result)[(*size) - 1] = number[len_int - 1];
            len_int--;
        }
        else if (elem->nul == 1 && elem->precision == 0)
        {
            //printf("hi1\n");
            (*result)[(*size) - 1] = '0';
        }
        (*size)--;
    }
}

void write_left_16(char **result, int *size, char *number)
{
    int i;
    int i1;
    int len_num;

    len_num = ft_strlen(number);
    i1 = 0;
    i = 0;
    while (i != (*size))
    {
        if (len_num != i1)
        {
            (*result)[i] = number[i1];
            i1++;
        }
        i++;
    }
}

void write_16_elem(t_spec *elem, char *number)
{
    int size;
    char *result;
    int i;

    i = 0;
    check_size_16(&elem, &size, &number);
    //printf("size - %i\n", size);
    result = (char *)malloc(sizeof(char) * (size + 1));
    result[size] = '\0';
    while (i != size)
    {
        result[i] = ' ';
        i++;
    }
    //printf("i - %i\n", ft_strlen(result));
    if (elem->minus == 1)
    {
        elem->left = 1;
    }
    if (elem->precision != 0)
    {
        //printf("hi\n");
        check_precision_16(&result, &size, elem, number);
    }
    else
    {
        if (elem->left == 1)
        {
            write_left_16(&result, &size, number);
        }
        else
        {
            //printf("hi\n");
            write_right_16(&size, number, &result, elem);
        }
    }
    //printf("==%s|\n", result);
    if (elem->nul == 1 && elem->precision == 0)
    {
        //printf("helllo\n");
        write_nul_or_probel(&result, '0', elem);
    }
    else
    {
        //printf("bye\n");
        write_nul_or_probel(&result, ' ', elem);
    }
    //printf("- |%i|\n", ft_strlen(result));
    elem->len = ft_strlen(result);
    ft_putstr(result);
    //free(result);
}

void convert_number(t_spec *elem, va_list ap)
{
    long long number;
    int mod;
    long long copy_number;
    char *new_number;
    int k;

    k = 0;
    new_number = 0;
    va_arg_type(elem, ap, &number);
    //printf("%lli\n", number);
    copy_number = number;
    while (number > 0)
    {
        number = number / 16;
        k++;
    }
    if (copy_number == 0)
    {
        new_number = (char *)malloc(sizeof(char) * (2));
        new_number = "0\0";
        write_16_elem(elem, new_number);
        return ;
    }
    else
    {
        new_number = (char *)malloc(sizeof(char) * (k + 1));
        new_number[k] = '\0';
    }
    while (copy_number > 0)
    {
        mod = copy_number % 16;
        if (mod >= 10 && mod <= 15 && elem->conv_type == 'x')
        {
            write_letter_a(mod, &new_number, k);
        }
        else if(mod >= 10 && mod <= 15 && elem->conv_type == 'X')
        {
            write_letter_A(mod, &new_number, k);
        }
        else
            new_number[k - 1] = mod + 48;
        copy_number = copy_number / 16;
        k--;
    }
    //printf("nubmer |%s|\n", new_number);
    write_16_elem(elem, new_number);
    //printf("nubmer |%s|\n", new_number);
}










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
    //int count;

    //count = ft_intlen(number);
    i = 0;
    //printf("hey\n");
    while ((*size) != i)
    {
        if (number != 0 || (number == 0 && elem->it_nul == 1))
        {
            mod = number % 10;
            number = number / 10;
            (*result)[(*size) - 1] = (char) mod + 48;
            elem->it_nul--;
        }
        else if (elem->nul == 1 && elem->minus == 0 && elem->precision == 0)
        {
            if (elem->plus == 1 && (*size) != 1)
                (*result)[(*size) - 1] = 48;
            //count++;
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
    if (elem->plus == 1 || elem->negative == 1 || elem->probel == 1)
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

/*void check_flag(char **result, int *size, t_spec *elem, int number)
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
    printf("result - %s\n", (*result));
}*/

void check_size_and_negative_int(t_spec **elem, int *size, long long *number)
{
    *size = 0;
    if ((*elem)->plus == 1 || (*number) < 0 || (*elem)->probel == 1)
    {
        if ((*number) < 0)
        {
            //printf("oqrv\n");
            (*elem)->negative = 1;
            *number = - (*number);
            //printf("number |%i|\n", *number);
        }
        (*size)++;
    }
    if ((*elem)->precision != 0 && (*elem)->precision > ft_intlen(*number))
    {
        (*size) = (*size) + (*elem)->precision;
    }
    else
    {
        (*size) = (*size) + ft_intlen(*number);
    }
    if ((*elem)->field != 0 && (*elem)->field > (*size))
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
    //printf("res - %s\n", (*result));
    if (elem->plus == 1 || elem->negative == 1 || elem->probel == 1)
        i++;
    while (i != len)
    {
        if (((*result)[i] >= '0' && (*result)[i] <= '9') || ((*result)[i] >= 'a' && (*result)[i] <= 'f') || ((*result)[i] >= 'A' && (*result)[i] <= 'F'))
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
    long long number;
    char *result;
    int i;
    int len;

    len = 0;
    i = 0;
    //printf("%d\n", ft_strlen(elem->modif));
    //number = va_arg(ap, int);
    va_arg_type(elem, ap, &number);
    if (number == 0)
    {
        elem->it_nul = 1;
    }
    check_size_and_negative_int(&elem, &size, &number);
    //printf("modif - %i\n", size);
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
    elem->len = ft_strlen(result);
    ft_putstr(result);
    //check_modif(&result, &size, elem);
}

void ft_create_str(t_spec *elem, va_list ap)
{
    
    if (elem->conv_type == 'd' || elem->conv_type == 'i' || elem->conv_type == 'u')
    {
        //printf("oioi\n");
        write_int_elem(elem, ap);
    }
    else if (elem->conv_type == 'o')
    {;}
    else if (elem->conv_type == 'x' || elem->conv_type == 'X')
    {
        convert_number(elem, ap);
    }
    else if (elem->conv_type == 'c')
    {;}
    else if (elem->conv_type == 's')
    {
        write_str_elem(elem, ap);
    }
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
    (*elem)->it_nul = 0;
}

int ft_create_elem(const char *format, int start, int end, va_list ap)
{
    t_spec *elem;
    int i;
    int size;
    int result;

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
    //free(elem->conv_type);
    //free(elem->modif);
    result = elem->len;
    free(elem);
    return (result);
}


int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int k;
    int z;
    int count;

    count = 0;
    z = -1;
    i = 0;
    k = 0;
    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            z = i;
            while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' 
            && format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && 
            format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && format[i] != 'f')
            {
                i++;
            }
            //printf("k = %c\n i = %c\n", format[k], format[i]);
            //i = k;
            k = k + ft_create_elem(format, z + 1, i, ap);
            count++;
            //printf("--%i\n", ft_create_elem(format, k + 1, i, ap));
        }
        else
        {
            ft_putchar(format[i]);
        }
        i++;
        k++;
    }
    va_end(ap);
    if (count == 0)
        return (k);
    //printf("i - %i\n", k);
    return (k - count);
}

/*int main()
{
    ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
    printf("@moulitest: %5.d %5.0d\n", 0, 0);
    return (0);
}*/