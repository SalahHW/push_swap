/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:56:22 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/21 02:33:34 by sbouheni         ###   ########.fr       */
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
		a_list_ptr->ra = actual_position;
		a_list_ptr->rb = futur_position;
		a_list_ptr->rra = lst_length(a_list) - actual_position;
		a_list_ptr->rrb = lst_length(a_list) - futur_position;
		if (a_list_ptr->ra > a_list_ptr->rb)
			a_list_ptr->rr = a_list_ptr->ra - a_list_ptr->rb;
		else
			a_list_ptr->rr = a_list_ptr->rb - a_list_ptr->ra;
		if (a_list_ptr->rra > a_list_ptr->rrb)
			a_list_ptr->rrr = a_list_ptr->rra - a_list_ptr->rrb;
		else
			a_list_ptr->rrr = a_list_ptr->rrb - a_list_ptr->rra;
		simplify_move(a_list_ptr);
    a_list_ptr = a_list_ptr->next;
	}
}

void	simplify_move(t_stack *a_element)
{
	int	minimum_move;

	minimum_move = a_element->ra + a_element->rb;
	if (rra_rrb_calculation(a_element) < minimum_move)
		minimum_move = rra_rrb_calculation(a_element);
	if (rr_ra_rb_calculation(a_element) < minimum_move)
		minimum_move = rr_ra_rb_calculation(a_element);
	if (rrr_rra_rrb_calculation(a_element) < minimum_move)
		minimum_move = rrr_rra_rrb_calculation(a_element);
	if (ra_rrb_calculation(a_element) < minimum_move)
		minimum_move = ra_rrb_calculation(a_element);
	if (rra_rb_calculation(a_element) < minimum_move)
		minimum_move = rra_rb_calculation(a_element);
	if (rra_rrb_calculation(a_element) == minimum_move)
		rra_rrb_application(a_element);
	else if (rr_ra_rb_calculation(a_element) == minimum_move)
		rr_ra_rb_application(a_element);
	else if (rrr_rra_rrb_calculation(a_element) == minimum_move)
		rrr_rra_rrb_application(a_element);
	else if (ra_rrb_calculation(a_element) == minimum_move)
		ra_rrb_application(a_element);
	else if (rra_rb_calculation(a_element) == minimum_move)
		rra_rb_application(a_element);
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

int	get_total(t_stack *a_element)
{
	int	total;

	total = 0;
	total += a_element->ra;
	total += a_element->rb;
	total += a_element->rr;
	total += a_element->rra;
	total += a_element->rrb;
	total += a_element->rrr;
	return (total);
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
