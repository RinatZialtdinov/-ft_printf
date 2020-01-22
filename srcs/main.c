#include "printf.h"

int main()
{
    //#define LDBL_MANT_DIG = 128;
    //static char *s_hidden = "hi low\0don't print me lol\0";
    ft_printf("%.16f|\n", 0.000000000000000100);
    printf("%.16f|\n", 0.000000000000000100);
    //printf(" <-i  -  %i\n", ft_printf("%f|\n", 12.2));
    //printf(" <-i  -  %i\n", printf("%f|\n", 12.2));
     return (0);
}
