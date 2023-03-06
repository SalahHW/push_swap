/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:39:24 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/06 22:49:34 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	extract_values(int_list **list, int argc, char **argv)
{
	int i;
	int	n;

	i = 0;
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		push(list, n);
	}
	return (0);
}
