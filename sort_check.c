
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
            res = sa[i] - sb[i];
			if (res != 0)
                return (res);
			i++;
		}
        return (0);
	}
    return (-1);
}


int count_and_is_already_sorted(t_list_swap *a)
{
    t_elem_list *current;
    int iter;

    iter = 0;

    current = a->first;
    while(current !=NULL)
    {
        if (current->down !=NULL)
        {
            //if (current->nb > current->down->nb)
             //   return (0);
        }
        iter++;
        current = current->down;
    }

    return (iter);
}

int elem_max_pos(t_list_swap *a)
{
    t_elem_list *current;
    int max;
    int pos;
    int res;

    pos = 1;
    res = 1;
    if (a && a->first != NULL && a->first->down != NULL )
    {
        current = a->first;
        max  = current->nb;
        while(current != NULL)
        {

            if (current->nb > max)
            {
                res = pos;
                max = current->nb;
            }
            pos++;
            current = current->down; 
        }
    }
    return (res);
}

char *small_input_sorting(t_list_swap *a,t_list_swap *b, int len)
{
    (void) *b;
    char *res;
    
    if (len == 2)
        res = sort_two_elem(a, NULL);
    else if 
        (len == 3)
        res = sort_three_elem(a, NULL);
    else
        return(NULL);
    return(res);
}

char    *sort_two_elem(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *current;
    char    *res;

    if (elem_max_pos(a) == 1)
        res = write_and_operation (a, b,"sa");
    if (a->first->nb == a->end->nb)
        return (NULL);
    return (res);
}

char *sort_three_elem(t_list_swap *a, t_list_swap *b)
{
    t_elem_list *current;
    char    *res;
    int flag;
    
    if (elem_max_pos(a) == 1)
    {
        if (a->first->down->nb > a->end->nb)
            res = ft_strjoin(write_and_operation (a, b,"ra"),write_and_operation (a, b,"sa"));
        else if (a->first->down->nb < a->end->nb)
            res = write_and_operation (a, b,"ra");
        else
         return(delete_and_return(a));
    }
    else if (elem_max_pos(a) == 2)
    {
        
        if (a->first->nb > a->end->nb)
            res = ft_strjoin(write_and_operation (a, b,"ra"),write_and_operation (a, b,"ra"));
        else if (a->first->nb < a->end->nb)
        {
            //res = ft_strjoin(write_and_operation (a, b,"sa"),write_and_operation (a, b,"ra"));
            res = ft_strjoin(write_and_operation (a, b,"ra"),write_and_operation (a, b,"sa"));
        }
        else
         return(delete_and_return(a));
    }
    else if (elem_max_pos(a) == 3)
    {
        if (a->first->nb > a->first->down->nb)
            res = write_and_operation (a, b,"sa");
        else if (a->first->nb < a->first->down->nb)
            return(NULL);
        else
            return(delete_and_return(a));
    }
    else
        return(NULL);

    return (res);
}

char    *delete_and_return(t_list_swap *a)
{
    FreeListe(a);
    //a = NULL;
    return(NULL);
}

int max_input_digit(t_list_swap *a)
{
    t_elem_list *current;
    int max;
    int max_bin_size;

    if (a && a->first != NULL)
    {
        current = a->first;
        max  = current->nb;
        max_bin_size  = ft_strlen(current->bin);
        while(current != NULL)
        {
            if (current->nb > max)
            {
                max = current->nb;
                max_bin_size = ft_strlen(current->bin);
            }
            current = current->down; 
        }
    }
    return (max_bin_size);
}

char *sort_radix(t_list_swap *a)
{
    int max_bin_size;
    t_elem_list *current;
    t_list_swap *b;
    //t_elem_list *pivot;
    char    digit;
    char    res;
    int flag;
    int flag_push;

    flag = 0;
    res = NULL;

    max_bin_size = max_input_digit(a);
    while (max_bin_size != 0)
    {
        if (flag_push == 1)
            FreeListe(b);
        current = a->first;
        flag_push = 0;
        //pivot = a->first;
        printf("HERE\n");
        while (current != NULL)
        {
            printf("current nb : %d\n",current->nb);
            
            if (a->first->bin[max_bin_size] == 0)
            {
                if (flag == 1)
                {
                    write_and_operation (a, b, "ra");
                    flag = 0;
                }
                else
                {
                    if (flag == 0)
                    {
                        printf("HERE1\n");
                        initialisation(&b,current->nb);
                        printf("HERE2\n");
                        ft_putstr("pb\n");
                        flag_push = 1;
                    }
                    else
                        write_and_operation (a, b, "pb");
                }

                current = a->first;
            }
            else
            {
                if (flag == 0)
                    {
                        //pivot = current;
                        flag = 1;
                    }
            }  
            current = current->down;
            printf("First AFTER nb : %d\n",a->first->nb);
            printf("current AFTER nb : %d\n",current->nb);
            if (b->first != NULL)
                printf("current nb : %d\n",b->first->nb);
        }
        max_bin_size --;
    }
    return (res);
}
