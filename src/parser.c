/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:20:03 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/22 04:22:26 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_values(char **argv)
{
	argv++;
	while (*argv)
	{
		if (!is_convertible_to_int(*argv))
			return (0);
		argv++;
	}
	return (1);
}

int	has_duplicate(t_edge *list)
{
	int		number;
	t_stack	*list_first_elem_ptr;
	t_stack	*list_ptr;

	list_first_elem_ptr = list->first;
	while (list_first_elem_ptr)
	{
		list_ptr = list_first_elem_ptr->next;
		number = list_first_elem_ptr->number;
		while (list_ptr)
		{
			if (number == list_ptr->number)
				return (1);
			list_ptr = list_ptr->next;
		}
		list_first_elem_ptr = list_first_elem_ptr->next;
	}
	return (0);
}
