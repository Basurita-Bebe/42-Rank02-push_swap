/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:03:12 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 10:04:22 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h> 

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*temp;

	if (count && size > SIZE_MAX / count)
	{
		return (NULL);
	}
	total_size = count * size;
	if (total_size == 0)
	{
		total_size = 0;
	}
	temp = malloc(total_size);
	if (!temp)
	{
		return (NULL);
	}
	ft_bzero(temp, total_size);
	return (temp);
}