/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:16:49 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/16 18:37:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

void	push_a(t_edge *a_list, t_edge *b_list)
{
	if (b_list->first)
	{
		push_front(a_list, b_list->first->number);
    pop_front(b_list);
    write(1, &"pa\n", 3);
	}
}

void	push_b(t_edge *a_list, t_edge *b_list)
{
	if (a_list->first)
	{
		push_front(b_list, a_list->first->number);
		pop_front(a_list);
    write(1, &"pb\n", 3);
	}
}
