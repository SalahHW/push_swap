/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:16:49 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/16 18:37:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(edge *a_list, edge *b_list)
{
	if (b_list->first)
	{
		push_front(a_list, b_list->first->number);
	}
}

void	push_b(edge *a_list, edge *b_list)
{
	if (a_list->first)
	{
		push_front(b_list, a_list->first->number);
		pop_front(b_list);
	}
}
