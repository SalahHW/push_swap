/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:39:24 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/25 06:00:44 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lst_length(t_edge *list)
{
	int		count;
	t_stack	*element;

	element = list->first;
	count = 0;
	while (element)
	{
		count++;
		element = element->next;
	}
	return (count);
}

int	is_sorted(t_edge *list)
{
	int		number1;
	int		number2;
	t_stack	*list_ptr1;
	t_stack	*list_ptr2;

	list_ptr1 = list->first;
	while (list_ptr1)
	{
		number1 = list_ptr1->number;
		list_ptr2 = list_ptr1->next;
		while (list_ptr2)
		{
			number2 = list_ptr2->number;
			if (number2 < number1)
				return (0);
			list_ptr2 = list_ptr2->next;
		}
		list_ptr1 = list_ptr1->next;
	}
	return (1);
}

int	is_reverse_sorted(t_edge *list)
{
	int		number1;
	int		number2;
	t_stack	*list_ptr1;
	t_stack	*list_ptr2;

	list_ptr1 = list->first;
	while (list_ptr1)
	{
		number1 = list_ptr1->number;
		list_ptr2 = list_ptr1->next;
		while (list_ptr2)
		{
			number2 = list_ptr2->number;
			if (number2 > number1)
				return (0);
			list_ptr2 = list_ptr2->next;
		}
		list_ptr1 = list_ptr1->next;
	}
	return (1);
}

int	greatest_number(t_edge *list)
{
	int		greatest_number;
	t_stack	*list_ptr;

	greatest_number = list->first->number;
	list_ptr = list->first;
	while (list_ptr)
	{
		if (list_ptr->number > greatest_number)
			greatest_number = list_ptr->number;
		list_ptr = list_ptr->next;
	}
	return (greatest_number);
}

int	smallest_number(t_edge *list)
{
	int		smallest_number;
	t_stack	*list_ptr;

	smallest_number = list->first->number;
	list_ptr = list->first;
	while (list_ptr)
	{
		if (list_ptr->number < smallest_number)
			smallest_number = list_ptr->number;
		list_ptr = list_ptr->next;
	}
	return (smallest_number);
}
