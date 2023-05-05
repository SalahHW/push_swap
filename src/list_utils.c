/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:39:24 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/03 19:41:22 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void	init(t_edge *list)
{
	list->first = NULL;
	list->last = NULL;
}

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

int	is_sorted(t_edge *list)
{
	int		tmp;
	t_stack	*list_first_elem_ptr;
	t_stack	*list_ptr;

	list_first_elem_ptr = list->first;
	while (list_first_elem_ptr)
	{
		list_ptr = list_first_elem_ptr->next;
		tmp = list_first_elem_ptr->number;
		while (list_ptr)
		{
			if (tmp < list_ptr->number)
				return (0);
			list_ptr = list_ptr->next;
		}
		list_first_elem_ptr = list_first_elem_ptr->next;
	}
	return (1);
}
