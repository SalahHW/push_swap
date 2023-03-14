/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:26:52 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/14 08:05:02 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct int_list
{
	int				number;
	struct int_list	*next;
	struct int_list	*prev;
}					int_list;

typedef struct
{
	int_list		*first;
	int_list		*last;
}					edge;

////			list_utils.c		////
void				init(edge *list);
void				push_back(edge *list, int value);
void				push_front(edge *list, int value);
void				clean_list(edge *list);
////			extract_values.c	////
int					extract_values(edge *listname, int argc, char **argv);
////			swap.c				////
void				swap_a(edge *a_list);
void				swap_b(edge *b_list);
void				swap_both(edge *a_list, edge *b_list);
////			push.c				////
void				push_a(edge *a_list, edge *b_list);
void				push_b(edge *a_list, edge *b_list);
////			rotate.c			////
void				rotate_a(void);
void				rotate_b(void);
void				rotate_both(void);
////			reverse_rotate.c	////
void				reverse_rotate_a(void);
void				reverse_rotate_b(void);
void				reverse_rotate_both(void);

#endif