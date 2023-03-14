/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:47:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/14 07:51:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(edge *list)
{
	list->last = NULL;
	list->first = NULL;
}

void	push_front(edge *list, int number)
{
	int_list	*new_element;

	new_element = malloc(sizeof(int_list));
	if (!new_element)
		return ;
	new_element->number = number;
	new_element->prev = list->first;
	new_element->next = NULL;
	if (list->first)
		list->first->next = new_element;
	else
		list->last = new_element;
	list->first = new_element;
}

void	push_back(edge *list, int number)
{
	int_list	*new_element;

	new_element = malloc(sizeof(int_list));
	if (!new_element)
		return ;
	new_element->number = number;
	new_element->next = list->last;
	new_element->prev = NULL;
	if (list->last)
		list->last->prev = new_element;
	else
		list->first = new_element;
	list->last = new_element;
}

void	clean_list(edge *list)
{
	int_list	*tmp;

	while (list->last)
	{
		tmp = list->first->prev;
		free(list->first);
		list->first = tmp;
	}
	init(list);
}
