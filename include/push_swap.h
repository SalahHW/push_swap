/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:26:52 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/30 15:29:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct
{
	t_stack			*first;
	t_stack			*last;
}					t_edge;

////			list_utils.c		////
void				init(t_edge *list);
void				push_front(t_edge *list, int value);
void				push_back(t_edge *list, int value);
void				pop_front(t_edge *list);
void				pop_back(t_edge *list);
////			extract_values.c	////
int					extract_values(t_edge *listname, int argc, char **argv);
////			swap.c				////
void				swap_a(t_edge *a_list);
void				swap_b(t_edge *b_list);
void				swap_both(t_edge *a_list, t_edge *b_list);
////			push.c				////
void				push_a(t_edge *a_list, t_edge *b_list);
void				push_b(t_edge *a_list, t_edge *b_list);
////			rotate.c			////
void				rotate_a(t_edge *a_list);
void				rotate_b(t_edge *b_list);
void				rotate_both(t_edge *a_list, t_edge *b_list);
////			reverse_rotate.c	////
void				reverse_rotate_a(t_edge *a_list);
void				reverse_rotate_b(t_edge *b_list);
void				reverse_rotate_both(t_edge *a_list, t_edge *b_list);

#endif
