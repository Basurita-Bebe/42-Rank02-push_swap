/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:03:12 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 10:04:22 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// For LONG_MIN and LONG_MAX
#include <limits.h>

// Helper function to check for overflow before performing the operation
static int	will_overflow(long result, int digit, int sign)
{
	long	check;

	// Check if result * 10 will overflow
	if (sign == 1)
	{
		check = (LONG_MAX - digit) / 10;
		if (result > check)
			return (1);
	}
	else
	{
		// For negative numbers, we check against LONG_MIN
		// Note: (LONG_MIN * -1) can't be stored in a long, so we adjust the math.
		check = (LONG_MIN + digit) / 10;
		if (result * -1 < check)
			return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	// 1. Handle leading whitespace
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	// 2. Handle optional sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// 3. Convert digits, checking for overflow at each step
	while (ft_isdigit(str[i]))
	{
		// Check if the next operation would cause an overflow
		if (will_overflow(result, (str[i] - '0'), sign))
		{
			// If it would overflow, return the maximum or minimum value
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		// Safe to perform the operation
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	// 4. Apply the sign and return
	return (result * sign);
}