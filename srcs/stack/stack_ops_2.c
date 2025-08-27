/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:48:04 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack_node **a, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second;
    t_stack_node    *last;

    // Safety check: Need at least 2 nodes to rotate
    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return ;
    // Step 1: Save references to key nodes
    first = *a;                   // Current head (will become head)
    second = (*a)->next;          // Second node (will become new head)
    last = find_last_node(*a);    // Current last node (will connect to first)

    // Step 2: Create temporary circular connection
    last->next = first;           // Last node now points to head
    first->prev = last;           // First node points back to last

    // Step 3: Update stack head to new top node
    *a = second;                // Second node is now head of the stack

    // Step 4: Clean up new head's pointers
    second->prev = NULL;          // New head has no previous node

    // Step 5: Clean up new tail's pointers
    first->next = NULL;           // New tail has no next node

    // Step 6: Print the operation
    if (print)
        printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second;
    t_stack_node    *last;

    if (b == NULL || *b == NULL || (*b)->next == NULL)
        return ;
    first = *b;
    second = (*b)->next;
    last = find_last_node(*b);
    last->next = first;
    first->prev = last;
    *b = second;
    second->prev = NULL;
    first->next = NULL;
    if (print)
        printf("rb\n");
}

void    rra(t_stack_node **a, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second_last;
    t_stack_node    *last;

    // Safety check: need at least 2 nodes to reverse rotate
    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return ;
    // Step 1: save references to key nodes
    first = *a;                     // Current head (will become 2nd node)  
    last = find_last_node(*a);      // Current last node (will become new head)
    second_last = last->prev;       // Node before last (will become new tail)

    // Step 2: Connect last node to first node
    last->next = first;             // Last node now points to first node
    first->prev = last;             // First node points back to last node

    // Step 3: Make second_last the new tail
    second_last->next = NULL;       // New tail has no next node

    // Step 4: Update stack head to the new top (last node)
    *a = last;                      // Last node is now the head of the stack
    last->prev = NULL;              // New head has no previous node

    // Step 5: Print the operation
    if (print)
        printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second_last;
    t_stack_node    *last;

    if (b == NULL || *b == NULL || (*b)->next == NULL)
        return ;
    first = *b;
    last = find_last_node(*b);
    second_last = last->prev;
    last->next = first;
    first->prev = last;
    second_last->next = NULL;
    *b = last;
    last->prev = NULL;
    if (print)
        printf("rrb\n");
}