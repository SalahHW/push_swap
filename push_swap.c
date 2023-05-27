/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:13:50 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 22:32:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_edge	a_list;
	t_edge	b_list;

	if (argc < 2)
		return (0);
	init(&a_list);
	init(&b_list);
	if (!extract_values(&a_list, argv))
		return (exit_error());
	if (!is_sorted(&a_list))
		sort(&a_list, &b_list);
	clear_list(&a_list);
	return (0);
}
