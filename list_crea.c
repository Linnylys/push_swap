
#include "push_swap.h"
#include <stdio.h>

t_list_swap *affect_list(char **str, int len)
{
    int i;
    int tmp;
    t_list_swap *res;

    i = len - 1;
    initialisation(&res,ft_atoi(str[len]));
    while (i > 0)
    {
        //afficherListe(res);
        tmp = ft_atoi(str[i]);
        //printf("tmp: %s - %d\n",str[i],tmp);
        insert(res,tmp);
        //afficherListe(res);
        //insert_elem(res, tmp, i);
        i--;
    }
    return (res);
}

int initialisation(t_list_swap **pliste,int first_nb)
{
    t_list_swap *liste;
    t_elem_list *elem;
    //t_elem_list *elem_end;

    liste = malloc(sizeof(*liste));
    elem = malloc(sizeof(*elem));
    if (liste == NULL || elem == NULL)
        return (0);
    elem->nb= first_nb;
    elem->up = NULL;
    elem->down = NULL;
    liste->first = elem;
    liste->end = elem;
    *pliste =liste;
    return (1);
}

int insert(t_list_swap *liste, int nb)
{
    t_elem_list *new;

    new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
        return (0);
    new->nb = nb;
    new->up = NULL;
    new->down = liste->first;
    liste->first = new;
    return (0);
}

int delete_first(t_list_swap *liste)
{
    if (liste == NULL)
        return (0);

    if (liste->first != NULL)
    {
        t_elem_list *todelete;
        todelete = liste->first;
        liste->first = liste->first->down;
        free(todelete);
    }
     return (0);
}

int delete_elem(t_list_swap *liste, int rnk)
{
    int i;

    i = 0;
    if (liste == NULL)
        return (0);

    t_elem_list *todelete;
    todelete = liste->first;
    while (i < rnk && todelete != NULL)
        todelete = todelete->down;
    todelete->up->down = todelete->down;
    todelete->down->up = todelete->up;
    free(todelete);
    return (0);
}

int insert_elem(t_list_swap *liste, int nb, int rnk)
{
    int i;
    t_elem_list *new;
    t_elem_list *seek;

    i = 0;
    new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
        return (0);
    seek = liste->first;
    new->nb = nb;
    while (i < rnk && seek != NULL)
        seek = seek->down;
    seek->up->down = new;
    new->up = seek->up;
    new->down = seek;
    seek->up = new; 
    seek->down->up = seek;
     return (0);
}

int afficherListe(t_list_swap *liste)
{
    if (liste == NULL)
        return (0);

    t_elem_list *current;

    current = liste->first;
    while (current != NULL)
    {
        printf("%d -> ", current->nb);
        current = current->down;
    }
    printf("NULL\n");
    return (0);
}

/*
int main()
{
    Liste *maListe = initialisation();

    insertion(maListe, 4);
    insertion(maListe, 8);
    insertion(maListe, 15);
    suppression(maListe);

    afficherListe(maListe);

    return 0;
}
*/