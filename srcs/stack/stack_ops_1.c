/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:47:47 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_stack_node **a, t_stack_node **b, bool print)
{
    t_stack_node    *node_to_move;
    (void)a;
    (void)b;
    (void)print;

    if (b == NULL || *b == NULL)    // Nothing to move
        return ;
    // step 1: Save reference to the top node of B
    node_to_move = *b;
    // step 2: Move B's head to the next node  
    *b = (*b)->next;
    // step 3: If there's a new top node, set its prev to NULL
    if (*b != NULL)                 
        (*b)->prev = NULL;
     // step 4: Prepare the moving node for its new place in A
    node_to_move->prev = NULL;      // It will be the new top of A
    node_to_move->next = *a;        // Point to whatever was top of A
    // step 5: If A wasn't empty, update its old top's prev pointer
    if (*a != NULL)
        (*a)->prev = node_to_move;
    // step 6: Make the moved node the new top of A
    *a = node_to_move;
    if (print)
        printf("pa\n");
}

void    pb(t_stack_node **a, t_stack_node **b, bool print)
{
    t_stack_node    *node_to_move;
    (void)a;
    (void)b;
    (void)print;

    if (a == NULL || *a == NULL)    // Nothing to move
        return ;  
    // step 1: Save reference to the top node of A
    node_to_move = *a;
    // step 2: Move A's head to the next node             
    *a = (*a)->next;
    // step 3: If there's a new top node, set its prev to NULL                
    if (*a != NULL)                 
        (*a)->prev = NULL;
    // step 4: Prepare the moving node for its new place in B        
    node_to_move->prev = NULL;      // It will be the new top of B
    node_to_move->next = *b;        // Point to whatever was top of B

    // step 5: If B wasn't empty, update its old top's prev pointer
    if (*b != NULL)
        (*b)->prev = node_to_move;
    // step 6: Make the moved node the new top of B
    *b = node_to_move;  
    if (print)
        printf("pb\n");
}

void    sa(t_stack_node **a, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second;

    // Check if swap is possible; we need at least 2 nodes
    if (a == NULL || *a == NULL || (*a)->next == NULL)
        return ;
    // Save reference of A head and A head->next  
    first = *a;
    second = (*a)->next;
    // step 1: first now points to what second was pointing
    first->next = second->next;
    // step 2: second now points to first
    second->next = first;
    // step 3: second's prev is now NULL (it becomes new top)
    second->prev = NULL;
    // step 4: first's prev is now second
    first->prev = second;
    // step 5: if there's a third node, update its prev pointer
    if (first->next != NULL)
        first->next->prev = first;
    // step 6: update stack head to point to new top (second)
    *a = second;
    if (print)
        printf("sa\n");
}

void    sb(t_stack_node **b, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second;

    if (b == NULL || *b == NULL || (*b)->next == NULL)
        return ;
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    if (first->next != NULL)
        first->next->prev = first;
    *b = second;
    if (print)
        printf("sb\n");
}