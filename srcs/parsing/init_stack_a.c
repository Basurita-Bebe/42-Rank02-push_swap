/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:45:21 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_stack_a(t_stack_node **a, char **args_array)
{
    int     i;
    long    number;

    i = 0;
    while (args_array[i] != NULL)
    {
        // 1. Validate each number string
        if (!is_valid_number(args_array[i]))
            error_exit(a, args_array, "Invalid number\n");
        // 2. Convert to long and check integer range
        number = ft_atol(args_array[i]);
        if (number > INT_MAX || number < INT_MIN)
            error_exit(a, args_array, "Number out of range\n");
        // 3. Create a node and add to stack a
        add_node_to_stack(a, create_node((int)number));
        i++;
    }
    // 4. Check for duplicates after building stack
    if (has_duplicate(*a))
        error_exit(a, args_array, "Duplicate number found\n");
}