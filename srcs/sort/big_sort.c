/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:49:05 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int  calculate_max_bits(int max_number)
{
    int max_bits;

    max_bits = 0;
    while (max_number > 0)
    {
        max_number = max_number >> 1;
        max_bits++;
    }
    return (max_bits);
}

static bool sorted_by_index(t_stack_node *stack)
{
    if (stack == NULL || stack->next == NULL)
        return (true);  
    while (stack->next != NULL)
    {
        if (stack->index > stack->next->index)
            return (false);
        stack = stack->next;
    }
    return (true);
}

static void radix_sort(t_stack_node **a, t_stack_node **b)
{
    int max_bits;
    int size;
    int i;
    int j;
    int count;

    size = stack_size(*a);
    if (size <= 1)
        return ;
    max_bits = calculate_max_bits(size - 1);
    // 1. Process each bit position fromLSB (0) to MSB
    for (i = 0; i < max_bits; i++)
    {
        count = 0;
        j = 0;
        // 1.1 Check if already sorted after each bit pass
        if (sorted_by_index(*a))
            break;
        // 2. Process all elements in the current stack
        while (j < size && count < size)
        {
            // 3. Check the i-th bit of the current top node's index
            if ((((*a)->index >> i) & 1) == 1)
                // 4.a. Bit is 1 -> keep in stack a and rotate
                ra(a, true);
            else
                // 4.b. Bit is 0 -> push to stack b
                pb(a, b, true);
            count++;
            j++;
        }
        // 5. Push everything back from stack a to stack b
        while (*b != NULL)
            pa(a, b, true);
        // 5.1 Check again after completing the pass
        if (sorted_by_index(*a))
            break;
    }
}

void big_sort(t_stack_node **a, t_stack_node **b)
{
    // 1. Normalize the stack (convert to 0-based indices)
    normalize_stack(a);
    // 2. Perform radix sort on the indices
    radix_sort(a, b);
}