/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:41:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/15 22:54:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three_element(t_edge *a_list)
{
	t_stack	*first_element;
	t_stack	*second_element;
	t_stack	*third_element;

	first_element = a_list->first;
	second_element = a_list->first->next;
	third_element = a_list->first->next->next;
}

static void	deep_sort(t_edge *a_list, t_edge *b_list)
{
	int	a_first_number;
	int	b_first_number;
	int	b_last_number;

	while (lst_length(a_list) > 3)
	{
		a_first_number = a_list->first->number;
		b_first_number = b_list->first->number;
		b_last_number = b_list->last->number;
		if (a_first_number > b_first_number)
			push_b(a_list, b_list);
		else if (a_first_number < b_last_number)
		{
			push_b(a_list, b_list);
			rotate_b(b_list);
		}
		else
		{
			init_cost(a_list);
			calculate_move(a_list, b_list);
			// execute_cheapest_move(a_list, b_list);
		}
	}
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
		deep_sort(a_list, b_list);
	}
}
