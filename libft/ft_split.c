/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:03:38 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 10:04:22 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static size_t	count_words(char const *str, char limiter)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == limiter)
			str++;
		if (*str)
			count++;
		while (*str && *str != limiter)
			str++;
	}
	return (count);
}

static void	free_all(char **words_arr, int i)
{
	while (i >= 0)
	{
		free(words_arr[i]);
		i--;
	}
	free(words_arr);
}

int	fill(char **words_arr, char const *s, char limiter)
{
	int		i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == limiter && *s)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != limiter)
				len++;
			words_arr[i] = malloc(len + 1);
			if (!words_arr[i])
			{
				free_all(words_arr, i - 1);
				return (1);
			}
			ft_strlcpy(words_arr[i], s, len + 1);
			s += len;
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**result;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result = malloc((words_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[words_count] = NULL;
	if (fill(result, s, c))
		return (NULL);
	return (result);
}
