/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:39:24 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/14 07:51:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

int	extract_values(edge *list, int argc, char **argv)
{
	int	i;
	int	n;

	i = argc;
	while (--i > 0)
	{
		n = ft_atoi(argv[i]);
		push_front(list, n);
	}
	return (0);
}
