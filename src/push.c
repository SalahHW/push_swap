/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:16:49 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/11 00:57:44 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(int_list **list, int number)
{
	int_list	*element;

	element = malloc(sizeof(int_list));
	if (!element)
		return;
	element->previous = *list;
	element->number = number;
	*list = element;
}

void	push_a(int_list **a_list, int_list **b_list)
{
	if (*b_list)
	{
		if(!*a_list)
		{
			*a_list = *b_list;
			*b_list = (*b_list)->previous;
			(*b_list)->previous = NULL;
		}
		push(a_list, (*b_list)->number);
		clean_list(b_list);
	}
}

void	push_b(int_list **a_list, int_list **b_list)
{
	if (*a_list)
	{
		if(!*b_list)
		{
			*b_list = *a_list;
			*a_list = (*a_list)->previous;
			(*b_list)->previous = NULL;
			return;
		}
		push(b_list, (*a_list)->number);
		clean_list(a_list);
	}
}
