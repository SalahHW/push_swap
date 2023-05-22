/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:37:30 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/22 04:17:47 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rra_rrb_calculation(t_stack *a_element)
{
	int	cost;

	cost = a_element->rra + a_element->rrb;
	return (cost);
}

int	rr_ra_rb_calculation(t_stack *a_element)
{
	int	cost;

	cost = (a_element->ra - a_element->rr) + (a_element->rb - a_element->rr)
		+ a_element->rr;
	return (cost);
}

int	rrr_rra_rrb_calculation(t_stack *a_element)
{
	int	cost;

	cost = (a_element->rra - a_element->rrr) + (a_element->rrb - a_element->rrr)
		+ a_element->rrr;
	return (cost);
}

int	ra_rrb_calculation(t_stack *a_element)
{
	int	cost;

	cost = a_element->ra + a_element->rrb;
	return (cost);
}

int	rra_rb_calculation(t_stack *a_element)
{
	int	cost;

	cost = a_element->rra + a_element->rb;
	return (cost);
}
