
#include "push_swap.h"

int count_and_is_already_sorted(t_list_swap *a)
{
    t_elem_list *current;
    int iter;

    iter = 0;
    if (a && a->first != NULL && a->first->down != NULL )
    {
        current = a->first;
        while(current !=NULL)
        {
            if (current->down !=NULL)
            {
                if (current->nb > current->down->nb)
                    retrun (0);
            }
            iter++;
            current = current->down;
        }
    }
    return (iter);
}

int elem_max(t_list_swap *a)
{
    t_elem_list *current;
    int max;

    max = 1;
    if (a && a->first != NULL && a->first->down != NULL )
    {
        current = a->first;
        while(current != NULL)
        {
            if (current->nb > max)
                max = current->nb;
            current = current->down;
        }
    }
    return (max);
}

int small_input_sorting(t_list_swap *a, int len)
{
    if (len == 2)
        sort_two_elem(a);
    else if 
        (len == 3)
        sort_three_elem(a);
    else
        return(0);
    return(1);
}

int sort_two_elem(t_list_swap *a)
{
    t_elem_list *current;
    int flag;

    flag = 1;

    if (a && a->first != NULL && a->first->down != NULL )
    {
        current = a->first;
        while(current !=NULL)
        {
            if (current->down !=NULL)
            {
                if (current->nb > current->down->nb)
                    flag = 0;
            }
            current = current->down;
            iter++;
        }
    }
    return (flag);
}

int sort_three_elem(t_list_swap *a)
{
    t_elem_list *current;
    int flag;

    flag = 1;
    int iter[3];

    iter[0]=0;iter[1]=0;iter[2]=0;
    if (a && a->first != NULL && a->first->down != NULL )
    {
        current = a->first;
        while(current !=NULL)
        {
            if (current->down !=NULL)
            {
                if (current->nb > current->down->nb)
                    flag = 0;
            }
            current = current->down;
            iter++;
        }
    }
    return (flag);
}


