/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:04:49 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/22 04:08:30 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
