/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:02:32 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/27 16:42:46 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"
#include "push_swap.h"

void print_stack(t_stack_node *stack, char name)
{
    t_stack_node *current;
    
    if (stack == NULL)
    {
        printf("Stack %c is empty.\n", name);
        return;
    }
    
    printf("Stack %c:\n", name);
    printf(" TOP -> ");
    
    current = stack;
    while (current != NULL)
    {
        printf("[%d]", current->value);
        printf("(prev: ");
        if (current->prev == NULL)
            printf("NULL");
        else
            printf("%p", (void *)current->prev);
        printf(", next: ");
        if (current->next == NULL)
            printf("NULL");
        else
            printf("%p", (void *)current->next);
        printf(")");
        
        current = current->next;
        
        if (current != NULL)
            printf("\n      -> ");
    }
    
    printf("\n BOTTOM\n");
}

void test_validation(void)
{
    printf("Testing validation:\n");
    printf("'123': %d (should be 1)\n", is_valid_number("123"));
    printf("'-456': %d (should be 1)\n", is_valid_number("-456"));
    printf("'+789': %d (should be 1)\n", is_valid_number("+789"));
    printf("'': %d (should be 0)\n", is_valid_number(""));
    printf("'+': %d (should be 0)\n", is_valid_number("+"));
    printf("'12a34': %d (should be 0)\n", is_valid_number("12a34"));
    printf("'9999999999': %d (should be 0)\n", is_valid_number("9999999999"));
}

void test_memory_management(void)
{
    char **test_array;
    
    // Test 1: Array from ft_split
    test_array = ft_split("1 2 3", ' ');
    printf("Array from split:\n");
    for (int i = 0; test_array[i] != NULL; i++)
        printf("  %s\n", test_array[i]);
    free_array(test_array);
    printf("✓ Freed split array successfully\n");
    
    // Test 2: NULL array
    free_array(NULL);
    printf("✓ Handled NULL array without crash\n");
}