/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:41:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/20 09:33:55 by sbouheni         ###   ########.fr       */
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
	t_move	*a_moves;

	while (lst_length(a_list) > 3)
	{
		reset_cost(a_list);
		calculate_move(a_list, b_list);
		a_moves = find_cheapest_move(a_list);
		execute_cheapest_move(a_list, b_list, a_moves);
	}
	if (!is_sorted(a_list))
		sort_three_element(a_list);
	final_rotation(a_list, b_list);
}

void	execute_cheapest_move(t_edge *a_list, t_edge *b_list,
		t_move *a_moves)
{
	while (a_moves->ra > 0 && a_moves->rb > 0)
	{
		a_moves->ra--;
		a_moves->rb--;
		rotate_both(a_list, b_list);
	}
	while (a_moves->rra > 0 && a_moves->rrb > 0)
	{
		a_moves->rra--;
		a_moves->rrb--;
		reverse_rotate_both(a_list, b_list);
	}
	while (a_moves->ra-- > 0)
		rotate_a(a_list);
	while (a_moves->rra-- > 0)
		reverse_rotate_a(a_list);
	while (a_moves->rb-- > 0)
		rotate_b(b_list);
	while (a_moves->rrb-- > 0)
		reverse_rotate_b(b_list);
	push_b(a_list, b_list);
	free(a_moves);
}

void	sort(t_edge *a_list, t_edge *b_list)
{
	if (lst_length(a_list) < 3)
		rotate_a(a_list);
	else if (lst_length(a_list) == 3)
	{
		if (!is_sorted(a_list))
			sort_three_element(a_list);
	}
	else
	{
		push_b(a_list, b_list);
		push_b(a_list, b_list);
		deep_sort(a_list, b_list);
	}
}
