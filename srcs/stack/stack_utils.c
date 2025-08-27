/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:47:47 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node  *create_node(int value)
{
    t_stack_node    *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

t_stack_node  *find_last_node(t_stack_node *stack)
{
    t_stack_node *current;

    if (stack == NULL)
        return (NULL);
    current = stack;
    while (current != NULL && current->next != NULL)
        current = current->next;
    return (current);
}

void          add_node_to_stack(t_stack_node **stack, t_stack_node *new_node)
{
    if (!stack || !new_node)
        return ;
    if (*stack == NULL)
    {
        *stack = new_node;
        return ;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }

}

int           stack_size(t_stack_node *stack)
{
    int count;
    t_stack_node *current;

    count = 0;
    current = stack;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return (count);
}