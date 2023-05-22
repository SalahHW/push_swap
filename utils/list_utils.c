/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:39:24 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/22 04:24:37 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	init(t_edge *list)
{
	list->first = NULL;
	list->last = NULL;
}

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

int	extract_values(t_edge *list, int argc, char **argv)
{
	int	n;

	if (!check_values(argv))
		return (0);
	while (--argc > 0)
	{
		n = ft_atoi(argv[argc]);
		push_front(list, n);
	}
	if (has_duplicate(list))
	{
		clear_list(list);
		return (0);
	}
	return (1);
}