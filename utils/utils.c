/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:46:37 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 02:56:31 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(t_edge *list)
{
	list->first = NULL;
	list->last = NULL;
}

int	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
