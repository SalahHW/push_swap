/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_convert_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:26:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/04/08 08:49:09 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"
#include "../include/libft.h"

static int	is_white_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

int	is_convertible_to_int(char *argv)
{
	int		digit_count;
	char	*argv_ptr;

	argv_ptr = argv;
	digit_count = 0;
	if (*argv == '-' || *argv == '+')
		argv_ptr++;
	while (*argv_ptr)
	{
		if (digit_count > 10 || !ft_isdigit(*argv_ptr))
			return (0);
		digit_count++;
		argv_ptr++;
	}
	if (digit_count == 0)
		return (0);
	if (digit_count == 10)
	{
		if (ft_atol(argv) < -2147483648 || ft_atol(argv) > 2147483647)
			return (0);
	}
	return (1);
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