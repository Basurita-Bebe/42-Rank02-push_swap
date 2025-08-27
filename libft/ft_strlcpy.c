/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:55:28 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/21 09:55:32 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < dest_size)
		ft_memcpy(dest, src, src_len + 1);
	else if (dest_size != 0)
	{
		ft_memcpy(dest, src, dest_size -1);
		dest[dest_size - 1] = '\0';
	}
	return (src_len);
}