/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:34:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/17 06:03:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	find_position(t_edge *list, int num)
{
	int		i;
	t_stack	*element;

	element = list->first;
	i = 0;
	while (element->number != num)
	{
		element = element->next;
		i++;
	}
	return (i);
}

int	find_futur_position(t_stack *element, t_edge *b_list)
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
