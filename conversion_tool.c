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
    printf("div : %d\n",q/ 2);
    while (q/ 2 != 0)
    {
        printf("div loop: %d\n",q/ 2);
        q =  q /2;
        len ++;
    }
    res = malloc(len);
    printf("len : %d\n",len);
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