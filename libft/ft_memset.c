/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:02:22 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 10:04:22 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (!s || !c || n <= 0)
		return (NULL);
	temp = (unsigned char *) s;
	while (n > 0)
	{
		*(temp++) = (unsigned char) c;
		n--;
	}
	return (s);
}