/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 03:41:58 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/28 01:28:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

static int	execute_from_line(t_edge *a_list, t_edge *b_list, char *output_line)
{
	if (!ft_strncmp("sa\n", output_line, 3))
		swap_a(a_list, 0);
	else if (!ft_strncmp("sb\n", output_line, 3))
		swap_b(b_list, 0);
	else if (!ft_strncmp("ss\n", output_line, 3))
		swap_both(a_list, b_list, 0);
	else if (!ft_strncmp("ra\n", output_line, 3))
		rotate_a(a_list, 0);
	else if (!ft_strncmp("rb\n", output_line, 3))
		rotate_b(b_list, 0);
	else if (!ft_strncmp("rr\n", output_line, 3))
		rotate_both(a_list, b_list, 0);
	else if (!ft_strncmp("pa\n", output_line, 3))
		push_a(a_list, b_list, 0);
	else if (!ft_strncmp("pb\n", output_line, 3))
		push_b(a_list, b_list, 0);
	else if (!ft_strncmp("rra\n", output_line, 4))
		reverse_rotate_a(a_list, 0);
	else if (!ft_strncmp("rrb\n", output_line, 4))
		reverse_rotate_b(b_list, 0);
	else if (!ft_strncmp("rrr\n", output_line, 4))
		reverse_rotate_both(a_list, b_list, 0);
	else
		return (0);
	return (1);
}

static int	sort_from_output(t_edge *a_list, t_edge *b_list)
{
	char	*output_line;

	output_line = get_next_line(0);
	while (output_line)
	{
		if (!execute_from_line(a_list, b_list, output_line))
		{
			free(output_line);
			exit_error();
		}
		free(output_line);
		output_line = get_next_line(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_edge	a_checker;
	t_edge	b_checker;

	if (argc < 2)
		return (0);
	init(&a_checker);
	init(&b_checker);
	if (!extract_values(&a_checker, argv))
		return (exit_error());
	sort_from_output(&a_checker, &b_checker);
	if (is_sorted(&a_checker) && !b_checker.first)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_list(&a_checker);
	return (0);
}
