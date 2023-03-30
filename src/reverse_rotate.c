/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:54:37 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/30 15:29:05 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_edge *a_list)
{
	push_front(a_list, a_list->last->number);
	pop_back(a_list);
	write(1, &"rra\n", 4);
}

void	reverse_rotate_b(t_edge *b_list)
{
	push_front(b_list, b_list->last->number);
	pop_back(b_list);
	write(1, &"rrb\n", 4);
}

void	reverse_rotate_both(t_edge *a_list, t_edge *b_list)
{
	push_front(a_list, a_list->last->number);
	push_front(b_list, b_list->last->number);
	pop_back(a_list);
	pop_back(b_list);
	write(1, &"rrr\n", 4);
}
