/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:10:02 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/10 19:49:35 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> 
#include <stdio.h>


int	main(int argc, char **argv)
{
	//int	len;
	t_list_swap *input;
	t_list_swap *input_rot;
	t_list_swap *input_swap;
	t_list_swap *input_push;

	//len = argc - 1;
	//printf("Checl list : %d\n",check_list(argc, argv));
	if (check_list(argc, argv) == 0)
		return(1);
	input = affect_list(argv, argc - 1);
	input_rot = affect_list(argv, argc - 1);
	//input_swap = affect_list(argv, argc - 1);
	//input_push = affect_list(argv, argc - 1);
	
	printf("liste original \n");
	afficherListe(input);
	printf("Rotation liste original \n");
	rot_b(input,input_rot);
	afficherListe(input_rot);

	/*
	swap_b(input,input_swap);
	printf("liste swapped \n");
	afficherListe(input_swap);

	push_b(input, input_push);
	printf("liste original pushed list swapped \n");
	afficherListe(input);
	afficherListe(input_push);
	*/

	printf("liste original freeing \n");
	FreeListe(input);
	printf("Rotation liste original freeing\n");
	FreeListe(input_rot);
	/*
	printf("liste swapped freeing\n");
	FreeListe(input_swap);
	printf("liste original pushed list swapped freeing \n");
	FreeListe(input_push);
	*/

	return (0);
}

int check_list(int argc, char **list)
{
	int	i;
	int	j;

	i  = 1;
	if (argc < 2)
		return (0);
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (isnumber(list[i]) == 0 && isnumber(list[j]) == 0)
				return (0);
			if (atoi(list[i]) == atoi(list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int isnumber(char *list) 
{
	int	i;

	i = 0;
	while(list[i])
	{
		if (isalnum(list[i]) == 1)
		return (0);
		i++;
	}
	return (1);
}