/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_substrings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:51:01 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/24 15:52:28 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_free_substrings(char **substring)
{
	char **substring_ptr;

	substring_ptr = substring;
	while (*substring_ptr)
	{
		free(*substring_ptr);
		substring_ptr++;
	}
	free(substring);
}
