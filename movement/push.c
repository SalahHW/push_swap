/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:16:49 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/28 01:30:56 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_edge *a_list, t_edge *b_list, int write_move)
{
	if (b_list->first)
	{
		push_front(a_list, b_list->first->number);
		pop_front(b_list);
		if (write_move)
			ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_edge *a_list, t_edge *b_list, int write_move)
{
	if (a_list->first)
	{
		push_front(b_list, a_list->first->number);
		pop_front(a_list);
		if (write_move)
			ft_putstr_fd("pb\n", 1);
	}
}
