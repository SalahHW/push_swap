/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:13:50 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/15 21:51:06 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
	t_edge	a_list;
	t_edge	b_list;

	if (argc <= 2)
		return (-1);
	init(&a_list);
	init(&b_list);
	if (!extract_values(&a_list, argc, argv))
		return (print_error());
	init_cost(&a_list);
	if (!is_sorted(&a_list))
		sort(&a_list, &b_list);
	return (0);
}
