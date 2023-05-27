/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_convert_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:26:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/27 12:34:07 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static int	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

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
