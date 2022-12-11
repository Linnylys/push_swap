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
	int	len;

	len = argc - 1;
	if (check_list(argv) == 0)
		return(1);
	return (0);
}

int check_list(char **list)
{
	int	i;
	int	j;

	i  = 1;
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
