/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:25:02 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/16 18:36:44 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_edge a_list;
	t_edge b_list;

	init(&a_list);
	init(&b_list);
	extract_values(&a_list, argc, argv);
	push_b(&a_list, &b_list);
  pop_back(&a_list);
  pop_back(&a_list);
  pop_back(&a_list);
  pop_back(&a_list);
	return (0);
}
