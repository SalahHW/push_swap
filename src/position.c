/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:34:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/05 20:16:27 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int	find_position(t_edge list, int num)
{
	int	i;
	t_stack *element;

	element = list.first;
	i = 0;
	while(element->number != num)
	{
		element = element->next;
		i++;
	}
	return (i);
}

int find_futur_position(t_stack *element, t_edge *b_list)
{
  t_stack *b_list_ptr;
  int     number_a;
  int     number_b;
  int     next_number_b;

  number_a = element->number;
  b_list_ptr = b_list->first;

  while (b_list_ptr && b_list_ptr->next)
  {
    number_b = b_list_ptr->number;
    next_number_b = b_list_ptr->next->number;
    if (number_a < number_b && number_a > next_number_b)
    {
      return (find_position(*b_list, next_number_b));
    }
  }
  return (0);
}
