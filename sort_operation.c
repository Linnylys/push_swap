
#include "push_swap.h"

void swap_a(t_list_swap *a, t_list_swap *b)
{
    (void) *b;
    t_elem_list *elem;

    if (a->first != NULL && a->first->down != NULL )
    {
        elem = a->first->down;
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
    swap_a(a, b);
    swap_b(a, b);
}

void push_a(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;

    if (b ->first != NULL)
    {
        elem = b->first;
        elem->down = a->first;
        elem->up = NULL;
        a->first = elem; 
    }
}

void push_b(t_list_swap *a, t_list_swap *b)
{
    push_a(b, a);
}


void rot_a(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;

    if (b ->first != NULL)
    {
        elem = b->first;
        elem->down = a->first;
        elem->up = NULL;
        a->first = elem; 
    }
}