/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:37:30 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/21 01:14:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rra_rrb_calculation(t_stack *a_element)
{
	return (a_element->rra + a_element->rrb);
}

int	rr_ra_rb_calculation(t_stack *a_element)
{
	return ((a_element->ra - a_element->rr) + (a_element->rb - a_element->rr)
		+ a_element->rr);
}

int	rrr_rra_rrb_calculation(t_stack *a_element)
{
	return (a_element->rra - a_element->rrr);
}

int	ra_rrb_calculation(t_stack *a_element)
{
	return (a_element->ra + a_element->rrb);
}

int	rra_rb_calculation(t_stack *a_element)
{
	return (a_element->rra + a_element->rrb);
}
