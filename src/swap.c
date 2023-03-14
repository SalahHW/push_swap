/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:18:18 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/14 07:52:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int_list **list)
{
	int tmp;
	tmp = (*list)->prev->number;
	(*list)->prev->number = (*list)->number;		
	(*list)->number = tmp;
}

void	swap_a(int_list **a_list)
{
	if ((*a_list)->prev)
	{
		swap(a_list);
	}
}

void	swap_b(int_list **b_list)
{
	if ((*b_list)->prev)
	{
		swap(b_list);
	}
}

void	swap_both(int_list **a_list, int_list **b_list)
{
	if (*a_list)
	{
		swap(a_list);	
	}
	if (*b_list)
	{
		swap(b_list);
	}
}
