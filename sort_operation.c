
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
    t_elem_list *tmp;

    if (a && b && b ->first != NULL)
    {
        insert(a,b->first->nb);
        tmp = b->first->down;
        free(b->first);
        b->first = tmp;
    }
}

void push_b(t_list_swap *a, t_list_swap *b)
{
    push_a(b, a);
}

void rot_ra(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;
    t_elem_list *tmp;
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
        tmp = a->end->up;
        if (a->end)
            free(a->end);
        a->end = tmp;
        a->first = elem;
    }
}

void rot_rb(t_list_swap *a, t_list_swap *b)
{
    rot_ra(b, a);
}

void rot_rrr(t_list_swap *a, t_list_swap *b)
{
    rot_ra(a, NULL);
    rot_ra(b, NULL);
}

void rot_a(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;
    t_elem_list *tmp;
    (void) *b;

    elem = malloc(sizeof(*elem));
    if (a && a->first != NULL)
    {
        elem->nb = a->first->nb;
        elem->down = NULL;
        elem->up = a->end;
        a->end->down = elem;
        a->end = elem;
        a->first->down->up = NULL;
        tmp = a->first->down;
        if (a->first)
            free(a->first);
        a->first = tmp;
    }
}

void rot_b(t_list_swap *a, t_list_swap *b)
{
    rot_a(b, a);
}

void rot_rr(t_list_swap *a, t_list_swap *b)
{
    rot_a(a, NULL);
    rot_a(b, NULL);
}
