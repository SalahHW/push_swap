/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 04:20:03 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/22 18:19:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

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
