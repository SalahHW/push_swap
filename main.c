/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:13:50 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/30 15:28:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	main(int argc, char **argv)
{
		t_edge a_list;
		t_edge b_list;

	if (argc > 1)
	{
		init(&a_list);
		init(&b_list);
		extract_values(&a_list, argc, argv);
	}
}