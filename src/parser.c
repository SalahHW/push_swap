/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:20:03 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/26 15:11:19 by sbouheni         ###   ########.fr       */
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
	int	n;

	argv++;
	if (!check_values(argv))
		return (0);
	while (*argv)
	{
		n = ft_atoi(*argv);
		push_back(list, n);
		argv++;
	}
	if (has_duplicate(list))
	{
		clear_list(list);
		return (0);
	}
	return (1);
}

int	check_values(char **argument)
{
	if (!is_convertible_to_int(*argument))
		return (0);
	return (1);
}
