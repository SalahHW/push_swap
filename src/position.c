/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:34:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/19 19:59:14 by sbouheni         ###   ########.fr       */
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
	t_stack	*b_list_ptr;
	int		number_a;
	int		number_b;
	int		next_number_b;

	number_a = element->number;
	if (number_a > greatest_number(b_list))
		return (find_position(b_list, greatest_number(b_list)));
	else if (number_a < smallest_number(b_list))
		return (find_position(b_list, smallest_number(b_list)) + 1);
	b_list_ptr = b_list->first;
	while (b_list_ptr)
	{
		number_b = b_list_ptr->number;
		if (b_list_ptr->next)
		{
			next_number_b = b_list_ptr->next->number;
			b_list_ptr = b_list_ptr->next;
		}
		else
		{
			next_number_b = b_list->first->number;
			b_list_ptr = b_list->first;
		}
		if (number_a < number_b && number_a > next_number_b)
			return (find_position(b_list, next_number_b));
	}
	return (0);
}

void	final_rotation(t_edge *a_list, t_edge *b_list)
{
	t_stack	*b_element;
	int		futur_position;

	while (lst_length(b_list) > 0)
	{
		b_element = b_list->first;
		futur_position = find_futur_position_in_a(b_element, a_list);
		while (futur_position != 0)
		{
			if (futur_position > lst_length(a_list) / 2 + 1)
				reverse_rotate_a(a_list);
			else
				rotate_a(a_list);
			futur_position = find_futur_position_in_a(b_element, a_list);
		}
		push_a(a_list, b_list);
	}
	while (a_list->first->number != smallest_number(a_list))
	{
		if (find_position(a_list, smallest_number(a_list)) > lst_length(a_list)
			/ 2 + 1)
			reverse_rotate_a(a_list);
		else
			rotate_a(a_list);
	}
}
