/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:20:03 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/28 18:19:29 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_tab(char **tab)
{
	char	**tab_ptr;

	tab_ptr = tab;
	while (*tab_ptr)
	{
		free(*tab_ptr);
		tab_ptr++;
	}
	free(tab);
}

int	extract_values(t_edge *list, char **argv)
{
	argv++;
	while (*argv)
	{
		check_values(list, argv, 0);
		argv++;
	}
	if (has_duplicate(list))
	{
		clear_list(list);
		return (0);
	}
	return (1);
}

void	check_values(t_edge *list, char **argument, char **splited_values)
{
	char	**splited_values_ptr;

	if (has_white_space(*argument))
	{
		splited_values = ft_split_white_space(*argument);
		splited_values_ptr = splited_values;
		while (*splited_values_ptr)
		{
			check_values(list, splited_values_ptr, splited_values);
			splited_values_ptr++;
		}
		free_tab(splited_values);
		splited_values = 0;
	}
	else
	{
		check_multiple_zero(argument, splited_values);
		if (!is_convertible_to_int(*argument))
			exit_error();
		push_back(list, ft_atoi(*argument));
	}
}
