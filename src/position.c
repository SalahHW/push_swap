/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:34:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/23 15:18:08 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	find_position(t_edge *list, int num)
{
	int		position;
	t_stack	*element;

	element = list->first;
	position = 0;
	while (element->number != num)
	{
		element = element->next;
		position++;
	}
	return (position);
}

int	find_futur_position_in_a(t_stack *element, t_edge *a_list)
{
	t_stack	*a_list_ptr;
	int		number_b;
	int		position;

	number_b = element->number;
	position = 0;
	if (number_b < a_list->first->number && number_b > a_list->last->number)
		return (0);
	else if (number_b > greatest_number(a_list)
		|| number_b < smallest_number(a_list))
		return (find_position(a_list, smallest_number(a_list)));
	else
	{
		a_list_ptr = a_list->first;
		while (a_list_ptr->number > number_b
			|| a_list_ptr->next->number < number_b)
			a_list_ptr = a_list_ptr->next;
		position = find_position(a_list, a_list_ptr->next->number);
	}
	return (position);
}

int	find_futur_position_in_b(t_stack *element, t_edge *b_list)
{
	t_stack *b_list_ptr;
	int	position;

	position = 0;
	if (element->number > b_list->first->number && element->number
		< b_list->last->number)
		return (0);
	else if (element->number > greatest_number(b_list)
		|| element->number < smallest_number(b_list))
		return (find_position(b_list, greatest_number(b_list)));
	else
	{
		b_list_ptr = b_list->first;
		while (b_list_ptr->number < element->number
			|| b_list_ptr->next->number > element->number)
			b_list_ptr = b_list_ptr->next;
		position = find_position(b_list, b_list_ptr->next->number);
	}
	return (position);
}
