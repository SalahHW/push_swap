/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:25:02 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/11 00:58:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int_list *a_list;
	int_list *b_list;

	a_list = NULL;
	b_list = NULL;
	extract_values(&a_list, argc, argv);
	push_b(&a_list, &b_list);
	push_b(&a_list, &b_list);
	push_a(&a_list, &b_list);
	push_a(&a_list, &b_list);
	push_a(&a_list, &b_list);
	return (0);
}
