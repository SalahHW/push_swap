/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:47:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/11 00:20:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Create a new element int the a_list given as argument
void	push_to_a(int_list **list, int number)
{
	int_list	*element;

	element = malloc(sizeof(int_list));
	if (!element)
		return ;
	element->number = number;
	element->previous = *list;
	*list = element;
}

void	clean_list(int_list **list)
{
	int_list *tmp;

	if (*list)
	{
		tmp = (*list)->previous;
		free(*list);
		*list = tmp;
	}
}
