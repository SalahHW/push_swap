/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:36:40 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/30 15:28:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_edge *a_list)
{
	push_back(a_list, a_list->first->number);
	pop_front(a_list);
	write(1, &"ra\n", 3);
}

void	rotate_b(t_edge *b_list)
{
	push_back(b_list, b_list->first->number);
	pop_front(b_list);
	write(1, &"rb\n", 3);
}

void	rotate_both(t_edge *a_list, t_edge *b_list)
{
	push_back(a_list, a_list->first->number);
	push_back(b_list, b_list->first->number);
	pop_front(a_list);
	pop_front(b_list);
	write(1, &"rr\n", 3);
}
