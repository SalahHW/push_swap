/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:47:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/30 15:29:25 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init(t_edge *list)
{
	list->last = NULL;
	list->first = NULL;
}

void	push_front(t_edge *list, int value)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return ;
	new_element->number = value;
	new_element->next = list->first;
	new_element->prev = NULL;
	if (list->first)
		list->first->prev = new_element;
	else
		list->last = new_element;
	list->first = new_element;
}

void	push_back(t_edge *list, int value)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return ;
	new_element->number = value;
	new_element->prev = list->last;
	new_element->next = NULL;
	if (list->last)
		list->last->next = new_element;
	else
		list->first = new_element;
	list->last = new_element;
}

void	pop_front(t_edge *list)
{
	t_stack	*tmp;

	if (list->first)
	{
		tmp = list->first;
		list->first = list->first->next;
		if (list->first)
			list->first->prev = NULL;
		else
			list->last = NULL;
		free(tmp);
	}
}

void	pop_back(t_edge *list)
{
	t_stack	*tmp;

	if (list->last)
	{
		tmp = list->last;
		list->last = list->last->prev;
		if (list->last)
			list->last->next = NULL;
		else
			list->first = NULL;
		free(tmp);
	}
}
