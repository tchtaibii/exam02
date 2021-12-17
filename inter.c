int check_double(char *str, char c, int p)
{
    int i = 0;
    while (i < p)
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}
int main(int ac, char **av)
{
    int i = 0;
    int j;

    if( ac == 3)
    {
        while (av[1][i])
        {
            if(!check_double(av[1],av[1][i], i))
            {
                j = 0;
                while (av[2][j])
                {
                    if(av[1][i] == av[2][j])
                    {
                        write(1, &av[1][i], 1);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
        write(1, "\n", 1);
    }
}