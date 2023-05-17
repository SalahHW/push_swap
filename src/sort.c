/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:41:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/17 05:56:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three_element(t_edge *a_list)
{
	if (smallest_number(a_list) == a_list->first->number)
	{
		reverse_rotate_a(a_list);
		swap_a(a_list);
	}
	else if (greatest_number(a_list) == a_list->first->number)
	{
		rotate_a(a_list);
		if (!is_sorted(a_list))
			swap_a(a_list);
	}
	else
	{
		if (find_position(a_list, greatest_number(a_list)) == 1)
			reverse_rotate_a(a_list);
		else
			swap_a(a_list);
	}
}

static void	deep_sort(t_edge *a_list, t_edge *b_list)
{
	t_stack	*a_element;

	while (lst_length(a_list) > 3)
	{
		reset_cost(a_list);
		calculate_move(a_list, b_list);
		a_element = find_cheapest_move(a_list);
		execute_cheapest_move(a_list, b_list, a_element);
	}
	sort_three_element(a_list);
	while (b_list->first)
		push_a(a_list, b_list);
}

void	execute_cheapest_move(t_edge *a_list, t_edge *b_list,
		t_stack *a_element)
{
	while (a_element->ra-- > 0 && a_element->rb-- > 0)
		rotate_both(a_list, b_list);
	while (a_element->rra-- > 0 && a_element->rrb-- > 0)
		reverse_rotate_both(a_list, b_list);
	while (a_element->ra-- > 0)
		rotate_a(a_list);
	while (a_element->rra-- > 0)
		reverse_rotate_a(a_list);
	while (a_element->rb-- > 0)
		rotate_b(b_list);
	while (a_element->rrb-- > 0)
		reverse_rotate_b(b_list);
	push_b(a_list, b_list);
}

void	sort(t_edge *a_list, t_edge *b_list)
{
	if (lst_length(a_list) < 3)
		rotate_a(a_list);
	else if (lst_length(a_list) == 3)
		sort_three_element(a_list);
	else
	{
		push_b(a_list, b_list);
		push_b(a_list, b_list);
		if (!is_reverse_sorted(b_list))
			rotate_b(b_list);
		deep_sort(a_list, b_list);
	}
}
