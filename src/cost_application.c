/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:58:10 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/21 00:39:12 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra_rrb_application(t_stack *a_element)
{
  a_element->rra = a_element->rra - a_element->rrr;
  a_element->rrb = a_element->rrb - a_element->rrr;
  a_element->ra = 0;
  a_element->rb = 0;
  a_element->rr = 0;
  a_element->total = get_total(a_element);
}

void	rr_ra_rb_application(t_stack *a_element)
{
  a_element->ra = a_element->ra - a_element->rr;
  a_element->rb = a_element->rb - a_element->rr;
  a_element->rra = 0;
  a_element->rrb = 0;
  a_element->rrr = 0;
  a_element->total = get_total(a_element);
}

void	rrr_rra_rrb_application(t_stack *a_element)
{
  a_element->rra = a_element->rra - a_element->rrr;
  a_element->rrb = a_element->rrb - a_element->rrr;
  a_element->ra = 0;
  a_element->rb = 0;
  a_element->rr = 0;
  a_element->total = get_total(a_element);
}

void	ra_rrb_application(t_stack *a_element)
{
  a_element->rb = 0;
  a_element->rra = 0;
  a_element->rr = 0;
  a_element->rrr = 0;
  a_element->total = get_total(a_element);
}

void	rra_rb_application(t_stack *a_element)
{
  a_element->ra = 0;
  a_element->rrb = 0;
  a_element->rr = 0;
  a_element->rrr = 0;
  a_element->total = get_total(a_element);
}
