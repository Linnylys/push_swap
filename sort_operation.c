
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
    swap_a(a, b);
    swap_b(a, b);
}

void push_a(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;

    if (a && b && b ->first != NULL)
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
    t_elem_list *elem1;
    t_elem_list *elem2;
    (void) *b;

    //elem = malloc(sizeof(*elem));
    //if (elem == NULL)
    //    return (0);
    if (a && a->first != NULL)
    {
        elem1 = a->end;
        elem2 = a ->end->up;

        elem1->down = a->first;
        elem1->up = NULL;
        printf("valeur end: %d\n",a->end->nb );

        //a->first->up = elem;

    }
}

/*void rot_a(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *elem;

    if (a && b && b ->first != NULL)
    {
        elem = a->first;
        elem->down = a->first;
        elem->up = NULL;
        a->first = elem; 
    }
}*/