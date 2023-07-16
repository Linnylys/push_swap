
#include "push_swap.h"

void swap_a(t_list_swap *a, t_list_swap *b)
{
    (void) *b;
    t_elem_list *elem;

    if (a && a->first != NULL && a->first->down != NULL )
    {
        elem = a->first->down;
        a->first->down =  a->first->down->down;
        a->first->pos --;
        elem->down = a->first;
        elem->up = NULL;
        elem->pos ++;
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

        insert_bin(a,b->first->nb,b->first->bin);
        tmp = b->first->down;
        printf("study %s\n",tmp);

            free(b->first);
            b->first = tmp;
        if (tmp != NULL)
        {
            b->first->up = NULL;
            b->end->down = NULL;
        }

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
        elem->bin = a->end->bin;
        elem->down = a->first;
        elem->up = NULL;
        elem->pos= a->first->pos;
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
        elem->bin = a->first->bin;
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

char    *write_and_operation (t_list_swap *a, t_list_swap *b, char *str)
{
    char    *res;
     printf("yeah!! %s\n",str);
    if (ft_strcmp(str,"sa") == 0)
    {
        swap_a(a,b);
    }
    else if (ft_strcmp(str,"sb") == 0)
        swap_b(a,b);
    else if (ft_strcmp(str,"ss") == 0)
        swap_ss(a,b);
    else if (ft_strcmp(str,"pa") == 0)
        push_a(a,b);
    else if (ft_strcmp(str,"pb") == 0)
        push_b(a,b);
    else if (ft_strcmp(str,"ra") == 0)
    {
        rot_a(a,b);
    }
    else if (ft_strcmp(str,"rb") == 0)
        rot_b(a,b);
    else if (ft_strcmp(str,"rra") == 0)
        rot_ra(a,b);
    else if (ft_strcmp(str,"rrb") == 0)
        rot_rb(a,b);
    else if (ft_strcmp(str,"rr") == 0)
        rot_rr(a,b);
    else if (ft_strcmp(str,"rrr") == 0)
        rot_rrr(a,b);

    ft_putstr(str);
    ft_putstr("\n");
    res = ft_strjoin(str, "\n");
    return (res);
}

