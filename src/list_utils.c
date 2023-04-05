/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:39:24 by sbouheni          #+#    #+#             */
/*   Updated: 2023/04/05 02:17:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"

void  init(t_edge *list)
{
  list->first = NULL;
  list->last = NULL;
}

int check_values(t_stack *list)
{
  while (list != NULL)
    {
      if (!is_integer(list->number))
        return (0);
      list = list->next; 
    }
  return (1);
}

int	extract_values(t_edge *list, int argc, char **argv)
{
	int	i;
	int	n;

	i = argc;
	while (--i > 0)
	{
		n = ft_atoi(argv[i]);
		push_front(list, n);
	}
	return (0);
}
