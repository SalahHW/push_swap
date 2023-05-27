/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:18:18 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 03:15:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_edge *a_list, int write_move)
{
	int	first_value;
	int	second_value;

	if (a_list->first && a_list->first->next)
	{
		first_value = a_list->first->number;
		second_value = a_list->first->next->number;
		pop_front(a_list);
		pop_front(a_list);
		push_front(a_list, first_value);
		push_front(a_list, second_value);
		if (write_move)
			ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_edge *b_list, int write_move)
{
	int	first_value;
	int	second_value;

	if (b_list->first && b_list->first->next)
	{
		first_value = b_list->first->number;
		second_value = b_list->first->next->number;
		pop_front(b_list);
		pop_front(b_list);
		push_front(b_list, first_value);
		push_front(b_list, second_value);
		if (write_move)
			ft_putstr_fd("sb\n", 1);
	}
}

void	swap_both(t_edge *a_list, t_edge *b_list, int write_move)
{
	int	first_value_a;
	int	first_value_b;
	int	second_value_a;
	int	second_value_b;

	if (a_list->first && b_list->first && a_list->first->next
		&& b_list->first->next)
	{
		first_value_a = a_list->first->number;
		first_value_b = b_list->first->number;
		second_value_a = a_list->first->next->number;
		second_value_b = b_list->first->next->number;
		pop_front(a_list);
		pop_front(a_list);
		pop_front(b_list);
		pop_front(b_list);
		push_front(a_list, first_value_a);
		push_front(a_list, second_value_a);
		push_front(b_list, first_value_b);
		push_front(b_list, second_value_b);
		if (write_move)
			ft_putstr_fd("ss\n", 1);
	}
}
