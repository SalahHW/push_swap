/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:56:22 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/20 09:04:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calculate_move(t_edge *a_list, t_edge *b_list)
{
	t_stack	*a_list_ptr;
	int		actual_position;
	int		futur_position;

	a_list_ptr = a_list->first;
	while (a_list_ptr)
	{
		actual_position = find_position(a_list, a_list_ptr->number);
		futur_position = find_futur_position_in_b(a_list_ptr, b_list);
		if (actual_position > (lst_length(a_list) / 2) + 1)
			a_list_ptr->rra = lst_length(a_list) - actual_position;
		else
			a_list_ptr->ra = actual_position;
		if (futur_position > (lst_length(b_list) / 2) + 1)
			a_list_ptr->rrb = lst_length(b_list) - futur_position;
		else
			a_list_ptr->rb = futur_position;
//		simplify_move(a_list_ptr);
		a_list_ptr->total = a_list_ptr->ra + a_list_ptr->rb + a_list_ptr->rra
			+ a_list_ptr->rrb;
		a_list_ptr = a_list_ptr->next;
	}
}

void	simplify_moves(t_stack *a_element)
{
}

t_move	*find_cheapest_move(t_edge *a_list)
{
	t_move	*cheapest_move;
	t_stack	*a_list_ptr;

	cheapest_move = malloc(sizeof(t_move));
	if (!cheapest_move)
		return (NULL);
	cheapest_move->total = 2147483647;
	a_list_ptr = a_list->first;
	while (a_list_ptr)
	{
		if (a_list_ptr->total < cheapest_move->total)
		{
			cheapest_move->ra = a_list_ptr->ra;
			cheapest_move->rb = a_list_ptr->rb;
			cheapest_move->rr = a_list_ptr->rr;
			cheapest_move->rra = a_list_ptr->rra;
			cheapest_move->rrb = a_list_ptr->rrb;
			cheapest_move->rrr = a_list_ptr->rrr;
			cheapest_move->total = a_list_ptr->total;
		}
		a_list_ptr = a_list_ptr->next;
	}
	return (cheapest_move);
}

void	reset_cost(t_edge *a_list)
{
	t_stack	*a_list_ptr;

	a_list_ptr = a_list->first;
	while (a_list_ptr)
	{
		a_list_ptr->ra = 0;
		a_list_ptr->rb = 0;
		a_list_ptr->rr = 0;
		a_list_ptr->rra = 0;
		a_list_ptr->rrb = 0;
		a_list_ptr->rrr = 0;
		a_list_ptr->total = 0;
		a_list_ptr = a_list_ptr->next;
	}
}
