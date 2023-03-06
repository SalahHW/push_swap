/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:26:52 by sbouheni          #+#    #+#             */
/*   Updated: 2023/03/06 21:42:01 by sbouheni         ###   ########.fr       */
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

void			push(int_list **p, int value);
void			swap_a(void);
void			swap_b(void);
void			push_a(void);
void			push_b(void);
void			rotate_a(void);
void			rotate_b(void);
void			rotate_both(void);
void			reverse_rotate_a(void);
void			reverse_rotate_b(void);
void			reverse_rotate_both(void);
int				extract_values(int_list **listname, int argc, char **argv);

#endif
