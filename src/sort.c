/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:41:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/26 00:34:37 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_element(t_edge *a_list)
{
	if (smallest_number(a_list) == a_list->first->number)
	{
		reverse_rotate_a(a_list, 1);
		swap_a(a_list, 1);
	}
	else if (greatest_number(a_list) == a_list->first->number)
	{
		rotate_a(a_list, 1);
		if (!is_sorted(a_list))
			swap_a(a_list, 1);
	}
	else
	{
		if (find_position(a_list, greatest_number(a_list)) == 1)
			reverse_rotate_a(a_list, 1);
		else
			swap_a(a_list, 1);
	}
}

void	deep_sort(t_edge *a_list, t_edge *b_list)
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

void	sort(t_edge *a_list, t_edge *b_list)
{
	if (lst_length(a_list) < 3)
		rotate_a(a_list, 1);
	else if (lst_length(a_list) == 3)
	{
		if (!is_sorted(a_list))
			sort_three_element(a_list);
	}
	else
	{
		push_b(a_list, b_list, 1);
		push_b(a_list, b_list, 1);
		deep_sort(a_list, b_list);
	}
}

void	execute_cheapest_move(t_edge *a_list, t_edge *b_list, t_move *a_moves)
{
	while (a_moves->ra-- > 0)
		rotate_a(a_list, 1);
	while (a_moves->rra-- > 0)
		reverse_rotate_a(a_list, 1);
	while (a_moves->rb-- > 0)
		rotate_b(b_list, 1);
	while (a_moves->rrb-- > 0)
		reverse_rotate_b(b_list, 1);
	while (a_moves->rr-- > 0)
		rotate_both(a_list, b_list, 1);
	while (a_moves->rrr-- > 0)
		reverse_rotate_both(a_list, b_list, 1);
	push_b(a_list, b_list, 1);
	free(a_moves);
}

void	final_rotation(t_edge *a_list, t_edge *b_list)
{
	t_stack	*b_element;
	int		futur_position;

	while (lst_length(b_list) > 0)
	{
		b_element = b_list->first;
		futur_position = find_futur_position_in_a(b_element, a_list);
		while (futur_position != 0)
		{
			if (futur_position > lst_length(a_list) / 2)
				reverse_rotate_a(a_list, 1);
			else
				rotate_a(a_list, 1);
			futur_position = find_futur_position_in_a(b_element, a_list);
		}
		push_a(a_list, b_list, 1);
	}
	while (a_list->first->number != smallest_number(a_list))
	{
		if (find_position(a_list, smallest_number(a_list)) > lst_length(a_list)
			/ 2)
			reverse_rotate_a(a_list, 1);
		else
			rotate_a(a_list, 1);
	}
}
