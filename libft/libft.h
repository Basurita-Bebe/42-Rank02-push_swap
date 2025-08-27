/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:58:56 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:59:12 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// For size_t, malloc, free and write
# include <stdlib.h> 
# include <unistd.h> 

// Part 1 - Libc functions
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

// Part 2 - Additional functions
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);

#endif