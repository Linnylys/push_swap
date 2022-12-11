/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:35 by lsipile           #+#    #+#             */
/*   Updated: 2022/12/04 20:12:20 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"


/*typedef struct s_tile
{
	int				type;
	int				og_type;
	int				chck_fill;
	t_vector		pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;*/

typedef struct s_elem_list
{
	int				nb;
	struct s_elem_list	*up;
	struct s_elem_list	*down;
}	t_elem_list;

typedef struct s_list_swap
{
    t_elem_list *first;
} t_list_swap;


/*typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};*/

/*typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};*/


/*typedef struct s_param
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_player	play;
	t_tile		key;
	int			key_flag;
	t_tile		**map;
	t_tile		**item;
	t_nb_items	nb_item;
	t_Mapsize	mapsize;
	int			check_border;
}	t_param;*/

int check_list(char **list);
int isnumber(char *list);

#endif
