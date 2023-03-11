/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:26:52 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/11 01:02:54 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct int_list
{
	int			number;
	struct int_list	*previous;
}				int_list;

////			list_utils.c	////
void			push(int_list **list, int value);
int				extract_values(int_list **listname, int argc, char **argv);
void			clean_list(int_list **list);
////			swap.c			////
void			swap_a(int_list **a_list);
void			swap_b(int_list **b_list);
void			swap_both(int_list **a_list, int_list **b_list);
////			push.c			////
void			push_a(int_list **a_list, int_list **b_list);
void			push_b(int_list **a_list, int_list **b_list);

void			rotate_a(void);
void			rotate_b(void);
void			rotate_both(void);

void			reverse_rotate_a(void);
void			reverse_rotate_b(void);
void			reverse_rotate_both(void);


#endif
