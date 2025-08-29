/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:02:57 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/28 11:02:58 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Goal: Validate each number string and check for errors

bool    is_valid_number(char *str)
{
    int     i;
    long    number;

    i = 0;
    // 1. Check for NULL or empty string
    if (str == NULL || str[0] == '\0')
        return (false);
    // 2. Handle optional sign
    if (str[0] == '+' || str[0] == '-')
        i++;
    // 3. Check if there's at least one digit after the sign
    if (str[i] == '\0')
        return (false);
    // 4. Check all remaining characters are digits
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    // 5. Check for overflow/underflow with ft_atol
    number = ft_atol(str);
    if (number > INT_MAX || number < INT_MIN)
        return (false);
    return (true);
}

bool    has_duplicate(t_stack_node *stack)
{
    t_stack_node    *current;
    t_stack_node    *runner;

    if (stack == NULL)
        return (false);
    current = stack;
    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            if (current->value == runner->value)
                return (true);
            runner = runner->next;
        }
        current = current->next;
    }
    return (false);
}
