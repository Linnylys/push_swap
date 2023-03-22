
#include "push_swap.h"


void	ft_putstr(char *s)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int	ft_strcmp(char *sa,char *sb)
{
	int	i;
    int res;

	if (sa != NULL && sb != NULL)
	{
		i = 0;
		while (sa[i] != '\0' || sb[i] != '\0')
		{
			res = sa[i]
			i++;
		}
	}
}


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
                    return (0);
            }
            iter++;
            current = current->down;
        }
    }
    return (iter);
}

int elem_max_pos(t_list_swap *a)
{
    t_elem_list *current;
    int pos_max;
    int pos;

    pos_max = 1;
    pos = 1;
    if (a && a->first != NULL && a->first->down != NULL )
    {
        current = a->first;
        while(current != NULL)
        {
            if (current->nb > pos_max)
                pos_max = pos;
            current = current->down;
            pos ++;
        }
    }
    return (pos_max);
}

int small_input_sorting(t_list_swap *a, int len)
{
    if (len == 2)
        sort_two_elem(a, NULL);
    else if 
        (len == 3)
        sort_three_elem(a, NULL);
    else
        return(0);
    return(1);
}

int sort_two_elem(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *current;

    if (elem_max_pos(a) == 1)
        write_and_operation (a, b,"sa");
    return (1);
}

int sort_three_elem(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *current;
    int flag;

    if (elem_max_pos(a) == 1)
    {
        if (a->first->down > a->end)
        {
            write_and_operation (a, b,"rra");
            write_and_operation (a, b,"sa");
        }
        else
            write_and_operation (a, b,"rra");
    }
    else if (elem_max_pos(a) == 2)
    {
        if (a->first > a->end)
        {
            write_and_operation (a, b,"sa");
            write_and_operation (a, b,"ra");
        }
        else
            write_and_operation (a, b,"sa");
    }
    else if (elem_max_pos(a) == 3)
    {
        if (a->first < a->first->down)
            write_and_operation (a, b,"sa");
    }
    else
        return(0);
    return (1);
}


