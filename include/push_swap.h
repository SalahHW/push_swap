/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:26:52 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/03 19:42:44 by sbouheni         ###   ########.fr       */
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

typedef struct s_edge
{
	t_stack			*first;
	t_stack			*last;
}					t_edge;

///             list_utils.c
void				init(t_edge *list);
int					extract_values(t_edge *listname, int argc, char **argv);
int					has_correct_values(char **argv);
int					has_duplicate(t_edge *list);
int					is_sorted(t_edge *list);
///				list_movements.c
void				push_front(t_edge *list, int value);
void				push_back(t_edge *list, int value);
void				pop_front(t_edge *list);
void				pop_back(t_edge *list);
void				clear_list(t_edge *list);
///				swap.c
void				swap_a(t_edge *a_list);
void				swap_b(t_edge *b_list);
void				swap_both(t_edge *a_list, t_edge *b_list);
///				push.c
void				push_a(t_edge *a_list, t_edge *b_list);
void				push_b(t_edge *a_list, t_edge *b_list);
///				rotate.c
void				rotate_a(t_edge *a_list);
void				rotate_b(t_edge *b_list);
void				rotate_both(t_edge *a_list, t_edge *b_list);
///				reverse_rotate.c
void				reverse_rotate_a(t_edge *a_list);
void				reverse_rotate_b(t_edge *b_list);
void				reverse_rotate_both(t_edge *a_list, t_edge *b_list);
///				int_convert_utils.c
int					is_convertible_to_int(char *str);
long				ft_atol(char *str);
///				push_swap.c
void				push_swap(t_edge *a_list, t_edge *b_list);

#endif
