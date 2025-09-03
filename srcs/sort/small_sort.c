/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:49:05 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Goal: Sort stack a using the minimal number of operations for small input sizes.   */
/*       If there's -> 2 elements: simple swap if needed                              */
/*                  -> 3 elements: specific optimal sequence of ops                   */
/*                  -> 4-5 elements: Push smallest to B, sort 3, push back            */

static void sort_three(t_stack_node **a);
static void sort_four_five(t_stack_node **a, t_stack_node **b);

void    small_sort(t_stack_node **a, t_stack_node **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
    {
        if ((*a)->value > (*a)->next->value)
            sa(a, true);
    }
    else if (size == 3)
        sort_three(a);
    else if (size == 4 || size == 5)
        sort_four_five(a, b);
}

static void sort_three(t_stack_node **a)
{
    int first;
    int second;
    int third;

    first = (*a)->value;
    second = (*a)->next->value;
    third = (*a)->next->next->value;
    // Case 1: [3, 1, 2] -> ra
    if (first > second && second < third && first > third)
        ra(a, true);
    // Case 2: [2, 3, 1] -> rra
    else if (first < second && second > third && first > third)
        rra(a, true);
    // Case 3: [2, 1, 3] -> sa
    else if (first > second && second < third && first < third)
        sa(a, true);
    // Case 4: [3, 2, 1] -> sa + rra
    else if (first > second && second > third)
    {
        sa(a, true);
        rra(a, true);
    }
    // Case 5: [1, 3, 2] -> rra + sa
    else if (first < second && second > third && first < third)
    {
        rra(a, true);
        sa(a, true);
    }
}

static void sort_four_five(t_stack_node **a, t_stack_node **b)
{
    int size;
    int need_to_push;

    size = stack_size(*a);
    // Always 1 push for 4 nodes, and 2 for 5
    need_to_push = size -3;
    // 1. Push smallest element/s to b
    while (need_to_push > 0)
    {
        push_smallest(a, b);
        need_to_push--;
    }
    // 2. Sort remaining 3 elements in a
    sort_three(a);
    // 3. Push all elements back from b to a
    while (*b != NULL)
        pa(a, b, true);
}