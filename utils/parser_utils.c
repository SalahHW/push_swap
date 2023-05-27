/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:18:09 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 12:35:57 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	is_convertible_to_int(char *argv)
{
	int		digit_count;
	char	*argv_ptr;

	argv_ptr = argv;
	digit_count = 0;
	if (*argv_ptr == '-' || *argv_ptr == '+')
		argv_ptr++;
	while (*argv_ptr)
	{
		if (digit_count > 10 || !ft_isdigit(*argv_ptr))
			return (0);
		digit_count++;
		argv_ptr++;
	}
	if (digit_count == 0)
		return (0);
	if (ft_atol(argv) < -2147483648 || ft_atol(argv) > 2147483647)
		return (0);
	return (1);
}

int	has_value_behind(char *c)
{
	char	*ptr;

	ptr = c;
	ptr++;
	if (*ptr)
		return (1);
	return (0);
}
