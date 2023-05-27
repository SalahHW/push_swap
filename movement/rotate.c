/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:36:40 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 03:15:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_edge *a_list, int write_move)
{
	push_back(a_list, a_list->first->number);
	pop_front(a_list);
	if (write_move)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_edge *b_list, int write_move)
{
	push_back(b_list, b_list->first->number);
	pop_front(b_list);
	if (write_move)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_edge *a_list, t_edge *b_list, int write_move)
{
	push_back(a_list, a_list->first->number);
	push_back(b_list, b_list->first->number);
	pop_front(a_list);
	pop_front(b_list);
	if (write_move)
		ft_putstr_fd("rr\n", 1);
}
