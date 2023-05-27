/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:54:37 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 03:15:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_edge *a_list, int write_move)
{
	push_front(a_list, a_list->last->number);
	pop_back(a_list);
	if (write_move)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_edge *b_list, int write_move)
{
	push_front(b_list, b_list->last->number);
	pop_back(b_list);
	if (write_move)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_edge *a_list, t_edge *b_list, int write_move)
{
	push_front(a_list, a_list->last->number);
	pop_back(a_list);
	push_front(b_list, b_list->last->number);
	pop_back(b_list);
	if (write_move)
		ft_putstr_fd("rrr\n", 1);
}
