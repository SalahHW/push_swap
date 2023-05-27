/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_convert_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:26:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/28 00:59:40 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (is_white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

void	check_multiple_zero(char **str, char **splited_values)
{
	char	**ptr;

	ptr = str;
	if ((*ptr)[0] && ((*ptr)[0] == '-' || (*ptr)[0] == '+'))
	{
		if ((*ptr)[1] && ((*ptr)[1] == '0') && (*ptr)[2])
		{
			if (splited_values)
				free_tab(splited_values);
			exit_error();
		}
	}
	else if ((*ptr)[0] && ((*ptr)[0] == '0') && (*ptr)[1])
	{
		if (splited_values)
			free_tab(splited_values);
		exit_error();
	}
	return ;
}
