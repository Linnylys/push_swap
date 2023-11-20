
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

char *sort_radix(t_list_swap *a, int max_bin_size)
{
    //int max_bin_size;
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
    afficherListe_bin(a,"a");
    if (!a)
        return (NULL);
    //max_bin_size = max_input_digit(a);
    printf("max_bin_size ; %d\n",max_bin_size);
    //if (b)
    //    FreeListe(b);
    ft_putstr("-----DEBUT*******\n");
   
    //afficherListe(b);
    ft_putstr("-----Step 1*******\n");
    
    int pos;

    num_push = 0;
    initialisation_bin(&b,0);
    while (i < 4 )
    {
        printf("Deb BIG LOOP1 : %d\n",i);
        current = a->end;
        flag_push = 0;
        pos = 0;
 
        printf("count i : %d\n",i);
        while (current != NULL)
        {
                       
            bin_size = max_bin_size;
                printf("Deb loop1 - i: %d\n",i);
                afficherListe(a,"a");
                afficherListe2(a,"a");printf("\n");
                printf("Deb loop2 - current nb %d\n",current->nb);
                if (current->bin[bin_size - i -1] == '0')
                {
                    printf("------------------------\n");
                    printf("If the studied digit is 0\n");
                        afficherListe_bin(a,"a "); 
                        afficherListe_bin(b,"b ");
                         afficherListe2(a,"a - go up");printf("\n"); 
                        write_and_operation (a, b, "ra");
                         afficherListe2(a,"a ");
                         afficherListe2(b,"b ");printf("\n");
                        write_and_operation (a, b, "pb");
                        afficherListe(a,"a");
                         afficherListe(b,"b");
                         afficherListe2(a,"a");
                         afficherListe2(b,"b");printf("\n");
                        num_push ++;
                        //move_to_the_top(a,b,current,pos,30);
                        afficherListe_bin(a,"a"); 
                        afficherListe_bin(b,"b"); 
                        afficherListe2(a,"a");
                        printf("After operation\n");printf("\n--------------------\n");
                        flag = 0;
                        pos = -1;


                    //ft_putstr("reinit\n");
                    current = a->end;
                    //printf("Check after init pb : %s\n",current->bin);
                }
                else
                {
                    printf("If the studied digit is 1\n");
                    current = current->up;
                }  
                
          afficherListe_bin(a,"a");
          printf("After the IF condition - End loop\n");  
          pos++;
        }
        printf("\n First loop finished \n");  
        if ( num_push != 0)
            {
                printf("IF num_push is !=0 ");
                ft_putstr("-----PUSH A*******\n");
                //while ( num_push !=0)
                afficherListe_bin(a,"a");
                afficherListe_bin(b,"b");printf("\n");
           
                while (num_push >0)
                {
                printf("num_push : %d\n",num_push);                    
                afficherListe_bin(a,"a");
                afficherListe_bin(b,"b");
                printf("\n");
                    write_and_operation (a, b, "rb");
                    write_and_operation (a, b, "pa");
                    num_push --;
                    
                }
                initialisation_bin(&b,0);
                ft_putstr("-----PUSH A END*******\n");
                afficherListe_bin(a,"a");
                afficherListe_bin(b,"b");
                printf("\n");
            }
        

    ft_putstr("\n\nBIG Loop result i:");
    printf("%d\n",i);
    afficherListe_bin(a,"a");
    //afficherListe_bin(b);
        i++;
    }

    ft_putstr("\n\nExit\n");
    afficherListe_bin(a,"a");
    afficherListe_bin(b,"b");
    printf("\n");

    afficherListe(a,"a");
    afficherListe(b,"b");
    printf("\n");
    return (res);
}



int move_to_the_top(t_list_swap *a,t_list_swap *b,t_elem_list *current,int pos,int len_list)
{
    //int len_list;
    int count;

    count = 0;
    //len_list = a->end->pos - a->first->pos;
    afficherListe(a,"a");
    printf("BEFORE pos : %d\n",pos);
    printf("BEFORE nb : %d\n\n",current->nb);
    if (pos <= len_list/2)
    {
        while (pos <= len_list/2 && pos > 0)
        {
             printf("move2top\n");
             afficherListe_bin(a,"a");
            write_and_operation (a, b, "ra");
            printf("\npos : %d\n\n",pos);
            count++;
            pos --;
        }
        afficherListe_bin(a,"a");
        afficherListe_bin(b,"b");
         printf("\n");
        write_and_operation (a, b, "pb");
        while (count > 0)
        { 
            printf("move2top\n");
             afficherListe_bin(a,"a");
            write_and_operation (a, b, "rra");
           
            count --;
        }
        printf("\n");
    }
    else
    {
        while (pos > len_list/2 && pos > 0)
        {
             printf("move22top\n");
             afficherListe_bin(a,"a");
            write_and_operation (a, b, "rra");
            printf("pos : %d\n", pos);
            count++;
            pos--;
        }
        write_and_operation (a, b, "rra");
        write_and_operation (a, b, "pb");
        while (count > 0)
        {
             printf("move22top\n");
             afficherListe_bin(a,"a");
            write_and_operation (a, b, "ra");
            count --;
        }
    }
    return (0);
}