/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:41:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/12 16:30:09 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three_element(t_edge *a_list)
{
}

static void	slow_sort(t_edge *a_list, t_edge *b_list)
{
}

void	sort(t_edge *a_list, t_edge *b_list)
{
	if (lst_length(a_list) < 3)
		rotate_a(a_list);
	else if (lst_length(a_list) == 3)
		sort_three_element(a_list);
	else
		slow_sort(a_list, b_list);
}
