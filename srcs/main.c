#include "printf.h"

int main()
{
     // char a = 'b';
//     ft_printf("%c\n", a);
//     printf("%c\n", a);
    // ft_printf("% c\n", a);
    // printf("% c\n", a);
    // ft_printf("%+c\n", a);
    // printf("%+c\n", a);
    // ft_printf("%0c\n", a);
    // printf("%0c\n", a);
    // ft_printf("%#c\n", a);
    // printf("%#c\n", a);
    // ft_printf("% c\n", a);
    // printf("% c\n", a);
    // ft_printf("%10c\n", a);
    // printf("%10c\n", a);
    // ft_printf("%-5c%c\n", a, a);
    // printf("%-5c%c\n", a, a);
    // ft_printf("%c%c%c%c%c%\n", a, b, c, d, e, f);
    // printf("%c%c%c%c%c%c", a, b, c, d, e, f);
     // ft_printf("%c\n", a);
     // printf("%c\n", a);
     // ft_printf("%c\n", a);
     // printf("%c\n", a);
     // ft_printf("%#c%c\n", a, b);
     // printf("%#c%c\n", a, b);
     // printf("\"\\\n");
     // ft_printf("\"\\\n");
     printf("%%.2c | %.2c\n");
     ft_printf("%%.2c | %.2c\n");
     return (0);
}

// # 0070 
//   ft_printf("%.2c", NULL);
//   1. (    0) --> <--
//   2. (    1) -->^@<--

// # 0072 (char)
//   ft_printf("%c", 42);
//   1. (    0) -->0<--
//   2. (    1) -->*<--

// # 0073 (char)
//   ft_printf("%5c", 42);
//   1. (    0) -->000000<--
//   2. (    5) -->    *<--

// # 0074 (char)
//   ft_printf("%-5c", 42);
//   1. (    0) -->      <--
//   2. (    5) -->*    <--

// # 0075 (char)
//   ft_printf("@moulitest: %c", 0);
//   1. (   12) -->@moulitest: 0<--
//   2. (   13) -->@moulitest: ^@<--

// # 0076 (char)
//   ft_printf("%2c", 0);
//   1. (    0) -->000<--
//   2. (    2) --> ^@<--

// # 0077 (char)
//   ft_printf("null %c and text", 0);
//   1. (   14) -->null 0 and text<--
//   2. (   15) -->null ^@ and text<--

// # 0078 (char)
//   ft_printf("% c", 0);
//   1. (    0) -->0<--
//   2. (    1) -->^@<--