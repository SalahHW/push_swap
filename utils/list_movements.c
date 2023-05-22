/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:47:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/20 09:03:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Add an element in the front of the list
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

//Add an element int the back of the list
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

//Remove an element from the front of the list
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

//Remove an element from the back of the list
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

//Free all the allocated memory use by the list and set pointers to NULL
void	clear_list(t_edge *list)
{
	t_stack	*tmp;

	while (list->first)
	{
		tmp = list->first;
		list->first = list->first->next;
		free(tmp);
	}
	list->last = NULL;
	list->last = NULL;
}
