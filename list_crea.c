
#include "push_swap.h"


int *initialisation(t_list_swap *liste)
{
    t_elem_list *elem;

    liste = malloc(sizeof(*liste));
    elem = malloc(sizeof(*elem));
    if (liste == NULL || elem == NULL)
        return (0);

    elem->nb= 0;
    elem->up = NULL;
    elem->up = NULL;
    liste->premier = elem;
    return (1);
}

void insert(t_list_swap *liste, int nb)
{
    t_elem_list *new;

    new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
        return (0);
    new->nb = nb;
    new->up = NULL;
    new->down = liste->first;
    liste->first = new;
}

void delete_first(t_list_swap *liste)
{
    if (liste == NULL)
        return (0);

    if (liste->first != NULL)
    {
        t_elem_list *todelete;
        todelete = liste->fisrt;
        liste->first = liste->first->down;
        free(todelete);
    }
}

void delete_elem(t_list_swap *liste, int rnk)
{
    int i;

    i = 0;
    if (liste == NULL)
        return (0);

    t_elem_list *todelete;
    todelete = liste->fisrt;
    while (i < rnk && todelete != NULL)
        todelete = todelete->down;
    todelete->up->down = todelete->down;
    todelete->down->up = todelete->up;
    free(todelete);
}

void insert_elem(t_list_swap *liste, int nb, int rnk)
{
    int i;
    t_elem_list *new;
    t_elem_list *seek;

    i = 0;
    new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
        return (0);
    seek = liste->fisrt;
    new->nb = nb;
    while (i < rnk && seek != NULL)
        seek = seek->down;
    seek->up->down = new;
    new->up = seek->up;
    new->down = seek;
    seek->up = new; 
    seek->down->up = seek;
}

void afficherListe(t_list_swap *liste)
{
    if (liste == NULL)
        return (0);

    t_elem_list *current;

    current = liste->premier;
    while (current != NULL)
    {
        printf("%d -> ", current->nb);
        current = current->down;
    }
    printf("NULL\n");
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