
#include "push_swap.h"

void swap_a(t_list_swap *a, t_list_swap *b)
{
    (void) *b;
    t_elem_list *elem;

    if (a && a->first != NULL && a->first->down != NULL )
    {
        elem = a->first->down;
        a->first->down =  a->first->down->down;
        elem->down = a->first;
        elem->up = NULL;
        a->first = elem;
    }
}

void swap_b(t_list_swap *a, t_list_swap *b)
{
    swap_a(b, a);
}

void swap_ss(t_list_swap *a, t_list_swap *b)
{
    swap_a(a, NULL);
    swap_a(b, NULL);
}

void push_a(t_list_swap *a, t_list_swap *b)
{

    if (a && b && b ->first != NULL)
    {
        insert(a,b->first->nb);
        free(b->first);
        b->first = b->first->down;
    }
}

void push_b(t_list_swap *a, t_list_swap *b)
{
    push_a(b, a);
}

void rot_a(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;
    t_elem_list *elem2;
    (void) *b;

    elem = malloc(sizeof(*elem));
    //if (elem == NULL)
    //    return (0);
    if (a && a->first != NULL)
    {
        elem->nb = a->end->nb;
        elem->down = a->first;
        elem->up = NULL;
        a->end->up->down = NULL;
        if (a->end)
            free(a->end );
        a->end = a->end->up;
        a->first = elem;
    }
}

void rot_b(t_list_swap *a, t_list_swap *b)
{
    rot_a(b, a);
}