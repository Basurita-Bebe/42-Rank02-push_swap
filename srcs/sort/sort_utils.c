/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_urils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:06:05 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/29 10:06:49 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the smallest node in a satck
t_stack_node    *find_smallest(t_stack_node *stack)
{
    t_stack_node    *smallest;
    t_stack_node    *current;

    if (stack == NULL)
        return (NULL);
    smallest = stack;
    current = stack->next;
    while (current != NULL)
    {
        if (current->value < smallest-> value)
            smallest = current;
        current = current->next;
    }
    return (smallest);
}

// Find largest node in a stack
t_stack_node    *find_largest(t_stack_node *stack)
{
    t_stack_node    *largest;
    t_stack_node    *current;

    if (stack == NULL)
        return (NULL);
    largest = stack;
    current = stack->next;
    while (current != NULL)
    {
        if (current->value > largest->value)
            largest = current;
        current = current->next;
    }
    return (largest);
}

// Calculate distance from a specific node to top of stack
int distance_to_top(t_stack_node *stack, t_stack_node *target)
{
    int             distance;
    t_stack_node    *current;

    if (stack == NULL || target == NULL)
        return (0);
    distance = 0;
    current = stack;
    while (current != NULL && current != target)
    {
        distance++;
        current = current->next;
    }
    return (distance);
}

// Push smallest element/s to stack b
void    push_smallest(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *smallest;
    int             distance;

    // 1. Find smallest & calculate distance to top
    smallest = find_smallest(*a);
    if (smallest == NULL)
        return ;
    distance = distance_to_top(*a, smallest);
    // 2. Bring smallest to top optimal rotation
    while ((*a) != smallest)
    {
        if (distance <= stack_size(*a) / 2)
            ra(a, true);
        else
            rra(a, true);
    }
    // 3. Push to stack b
    pb(a, b, true);
}

void    normalize_stack (t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *runner;
    int             index;

    if (stack == NULL || *stack == NULL)
        return ;
    current = *stack;
    while (current != NULL)
    {
        index = 0;
        runner = *stack;
        while (runner != NULL)
        {
            if (runner->value < current->value)
                index++;
            runner = runner->next;
        }
        current->index = index;
        current = current->next;
    }
}