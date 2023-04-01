
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

int list_bin_update(t_list_swap *a, int max_bin_size)
{
    t_elem_list *current;
    char    *bin_updated;

    if (a)
      {  
    if (a == NULL)
        return (0);

    current = a->first;
    while (current != NULL)
    {
        bin_updated = convert_bin_updated(current->bin,max_bin_size);
        free(current->bin);
        current->bin = bin_updated;
        current = current->down;
    }
    return (0);
      }
    else
        return (-1);
}

char *sort_radix(t_list_swap *a)
{
    int max_bin_size;
    t_elem_list *current;
    t_list_swap *b;
    //t_elem_list *pivot;
    char    digit;
    char    *res;
    int flag;
    int bin_size;
    int flag_push;
    int num_push;
    int i;
    i = 0;
    flag = 0;
    res = NULL;

    ft_putstr("-----IN*******\n");
    ft_putstr("Affiche A : ");
    afficherListe(a);
    if (!a)
        return (NULL);
    max_bin_size = max_input_digit(a);
    printf("max_bin_size ; %d\n",max_bin_size);
    //if (b)
    //    FreeListe(b);
    ft_putstr("-----DEBUT*******\n");
   
    //afficherListe(b);
    ft_putstr("-----Step 1*******\n");
    

    num_push = 0;
    while (i < 3 )
    {
        if (flag_push == 1)
            afficherListe_bin(b);
        current = a->first;
        flag_push = 0;
        //pivot = a->first;
        //printf("HERE\n");
        //ft_putstr("-----Step 2*******\n");

        while (current != NULL)
        {
            //printf("current nb : %d\n",current->nb);
       
            //printf("Val0 bin : %s\n",a->first->bin);
            
            bin_size = ft_strlen(current->bin);
            //printf("print str: %d\n",bin_size);
            //ft_putstr("-----Step 2.0*******\n");
            ft_putstr("\n");
            if (bin_size > i)
            {
                //ft_putstr("-----Step 2.1*******\n");
                printf("Val bin current: %c\n",current->bin[bin_size - i - 1]);
                if (current->bin[bin_size - i -1] == '0')
                {
                    printf("Flag: %d\n",flag);
                    if (flag == 1)
                    {
                        write_and_operation (a, b, "ra");
                        flag = 0;
                    }
                    else
                    {
                        printf("Check pb : %s\n",current->bin);
                        if (flag_push == 0)
                        {
                            initialisation(&b,current->nb);
                            ft_putstr("Affiche B afetr init : ");
                            afficherListe_bin(b);
                            ft_putstr("pb\n");
                            num_push ++;
                            flag_push = 1;
                        }
                        else
                        {
                            write_and_operation (a, b, "pb");
                            num_push ++;
                            ft_putstr("Affiche B : ");
                            afficherListe_bin(b);
                        }
                        //printf("A check: current nb : %s\n",a->first->bin);
                        //if (b->first != NULL)
                        //    printf("B check : current nb : %s\n",b->first->bin);
                    }
                    ft_putstr("reinit\n");
                    current = a->first;
                    printf("Check after init pb : %s\n",current->bin);
                }
                else
                {
                    if (flag == 0)
                        {
                            //pivot = current;
                            flag = 1;
                        }
                    ft_putstr("current plus\n");
                    current = current->down;
                }  
                
            }


            //printf("i : %d\n",i);
            //afficherListe(a);
            //afficherListe(b);
            //printf("A : current nb : %s\n",current);
            //if (b->first != NULL)
            //    printf("B : current nb : %s\n",b->first->bin);
        }

        if ( num_push != 0)
            {
                while ( num_push !=0)
                {
                    write_and_operation (a, b, "pa");
                    num_push --;
                }
            }

    ft_putstr("\n\nLoop result\n");
    afficherListe_bin(a);
    afficherListe_bin(b);
        i++;
    }
    //printf("A : current nb : %d\n",a->first->nb);
   // if (b->first != NULL)
     //   printf("B : current nb : %d\n",b->first->nb);
    //afficherListe(a);
    //afficherListe(b);
    ft_putstr("\n\nExit\n");
    afficherListe_bin(a);
    afficherListe_bin(b);
    return (res);
}
