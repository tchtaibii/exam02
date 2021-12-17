#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int ft_putstr(char *str)
{
    int i = 0;
    if (!str)
        return (ft_putstr("(null)"));
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return i;
}

int ft_putnbr(int n)
{
    int c = 0;

   if (n == -2147483648)
      return(ft_putstr("-2147483648"));
    if (n < 0)
    {
        c += ft_putchar('-');
        n *= -1;
    }
    if (n >= 10)
    {
        c += ft_putnbr(n / 10);
        c += ft_putnbr(n % 10);
    }
    else
        c += ft_putchar(n + 48);
    return c;
}

int ft_puthex(unsigned int n)
{
    int c = 0;
    char base[] = "0123456789abcdef";
    if (n >= 16)
    {
        c += ft_putnbr(n / 16);
        c += ft_putnbr(n % 16);
    }
    else
        c += ft_putchar(base[n]);
    return c;
}

int ft_printf(const char *str, ...)
{
    int i;
    va_list  va;
    i = 0;
    int k = 0;

    va_start(va, str);
    while (str[k])
    {
        if(str[k] == '%')
        {
            k++;
            if (str[k] == 'd')
                i += ft_putnbr(va_arg(va, int));
            if (str[k] == 'x')
                i += ft_puthex(va_arg(va, unsigned int));
            if (str[k] == 's')
                i += ft_putstr(va_arg(va, char *));
        }
        else
            i += ft_putchar(str[k]);
        k++;
    }
    va_end(va);
    return i;
}
