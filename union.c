int check_doubles(char *str, char c, int p)
{
    int i = 0;

    while(i < p)
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}
int check_other(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}
int main(int ac, char **av)
{
    int i;

    if (ac == 3)
    {
        while (av[1][i])
        {
            if (!check_doubles(av[1], av[1][i], i))
                write(1, &av[1][i], 1);
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (!check_doubles(av[2], av[2][i], i))
                if(check_other(av[1], av[2][i]))
                    write(1, &av[2][i], 1);
            i++;
        }
        write(1, "\n", 1);
    }
}