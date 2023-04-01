#include "push_swap.h"


char	*convert_bin(int nb)
{
	int	q;
    int len;
    char *res;
    char    *grid;

    len = 1;
    grid = "01";
    q = nb;
    //printf("div : %d\n",q/ 2);
    while (q/ 2 != 0)
    {
       // printf("div loop: %d\n",q/ 2);
        q =  q /2;
        len ++;
    }
    res = malloc(len);
    //printf("len : %d\n",len);
    if (res == NULL)
        return (NULL);
    q = nb;
    res[len]= '\0';
    len --;
    while (len >= 0)
    {
        res[len] = grid[q % 2];
        q =  q /2;
        len --;
    }
    return (res);
}

char	*convert_bin_updated(char *bin, int max_digit)
{
    int len_bin;
    int i;
    char    *res;

    len_bin = ft_strlen(bin);
    i = 0;
    res =  malloc (max_digit + 1);
    while (i <= max_digit)
    {
        if ( i <= len_bin)
            res[max_digit - i] = bin[len_bin - i];
        else
            res[max_digit - i] = '0';
        i++;
    }
    return (res);
}

