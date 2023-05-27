/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:47:18 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 02:57:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_edge
{
	t_stack			*first;
	t_stack			*last;
}					t_edge;

typedef struct s_move
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_move;

//				push_swap.c
void				init(t_edge *list);
int					exit_error(void);
//				list_utils.c
int					lst_length(t_edge *list);
int					is_sorted(t_edge *list);
int					is_reverse_sorted(t_edge *list);
int					greatest_number(t_edge *list);
int					smallest_number(t_edge *list);
//				parser.c
int					extract_values(t_edge *listname, char **argv);
int					check_values(char **argv);
//				parser_utils.c
int					is_convertible_to_int(char *str);
int					has_duplicate(t_edge *list);
//				list_movements.c
void				push_front(t_edge *list, int value);
void				push_back(t_edge *list, int value);
void				pop_front(t_edge *list);
void				pop_back(t_edge *list);
void				clear_list(t_edge *list);
//				sort.c
void				sort(t_edge *a_list, t_edge *b_list);
void				execute_cheapest_move(t_edge *a_list, t_edge *b_list,
						t_move *a_element);
//				cost.c
void				calculate_move(t_edge *a_list, t_edge *b_list);
void				simplify_move(t_stack *a_element);
int					cost_evaluation(t_stack *a_element);
t_move				*find_cheapest_move(t_edge *a_list);
//				cost_utils.c
int					get_total(t_stack *a_element);
void				reset_cost(t_edge *a_list);
//				cost_calculation.c
int					rra_rrb_calculation(t_stack *a_element);
int					rr_ra_rb_calculation(t_stack *a_element);
int					rrr_rra_rrb_calculation(t_stack *a_element);
int					ra_rrb_calculation(t_stack *a_element);
int					rra_rb_calculation(t_stack *a_element);
//				cost_application.c
void				rra_rrb_application(t_stack *a_element);
void				rr_ra_rb_application(t_stack *a_element);
void				rrr_rra_rrb_application(t_stack *a_element);
void				ra_rrb_application(t_stack *a_element);
void				rra_rb_application(t_stack *a_element);
//				position.c
int					find_position(t_edge *list, int num);
int					find_futur_position_in_a(t_stack *element, t_edge *a_list);
int					find_futur_position_in_b(t_stack *element, t_edge *b_list);
void				final_rotation(t_edge *a_list, t_edge *b_list);
//				int_convert_utils.c
long				ft_atol(char *str);
//				swap.c
void				swap_a(t_edge *a_list, int write_move);
void				swap_b(t_edge *b_list, int write_move);
void				swap_both(t_edge *a_list, t_edge *b_list, int write_move);
//				push.c
void				push_a(t_edge *a_list, t_edge *b_list, int write_move);
void				push_b(t_edge *a_list, t_edge *b_list, int write_move);
//				rotate.c
void				rotate_a(t_edge *a_list, int write_move);
void				rotate_b(t_edge *b_list, int write_move);
void				rotate_both(t_edge *a_list, t_edge *b_list, int write_move);
//				reverse_rotate.c
void				reverse_rotate_a(t_edge *a_list, int write_move);
void				reverse_rotate_b(t_edge *b_list, int write_move);
void				reverse_rotate_both(t_edge *a_list, t_edge *b_list,
						int write_move);

#endif
