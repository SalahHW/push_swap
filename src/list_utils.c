/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:47:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/16 18:35:34 by sbouheni         ###   ########.fr       */
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
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
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
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
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

void	pop_front(edge *list)
{
	t_list	*tmp;

	if (!list->first)
    return ;
  tmp = list->first->next;
  free(list->first);
  list->first = tmp;
}

void	clear_list(edge *list)
{
	t_list	*tmp;
	t_list	*first_elem;

	first_elem = list->first;
	while (first_elem)
	{
		tmp = first_elem;
		first_elem = first_elem->prev;
		free(tmp);
	}
	init(list);
}
