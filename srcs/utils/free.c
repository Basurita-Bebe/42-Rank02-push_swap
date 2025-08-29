/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:49:38 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *next_node;

    if (stack == NULL || *stack == NULL)
        return ;
    current = *stack;
    while (current != NULL)
    {
        next_node = current->next; // Save next pointer before freeing current
        free(current);             // Free current node
        current = next_node;       // Move to the next node
    }
    *stack = NULL;                 // Set the stack pointer to NULL to avoid dangling pointers
}

void    free_array(char **array)
{
    int i;

    printf("free_array called with: %p\n", (void *)array);
    if (array == NULL)
    {
        printf("Array is NULL, returning\n");
        return ;
    }
    i = 0;
    while (array[i] != NULL)
    {
        printf("Freeing element %d: %p ('%s')\n", i, (void *)array[i], array[i]);
        free(array[i]);
        i++;
    }
    printf("Freeing array itself: %p\n", (void *)array);
    free(array);
    printf("free_array completed successfully\n");
}