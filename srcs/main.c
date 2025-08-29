/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:44:22 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../includes/testing.h"

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    char **args_array;
    
    if (argc == 1)
        return (0);
    
    // Test parsing and stack initialization
    args_array = parse_args(argc, argv);
    init_stack_a(&a, args_array);
    
    // If we get here, everything worked!
    printf("✓ Stack A created successfully!\n");
    printf("Stack size: %d\n", stack_size(a));
    print_stack(a, 'a');
    
    // Test if sorted
    if (stack_is_sorted(a))
        printf("✓ Stack is already sorted!\n");
    else
        printf("✗ Stack needs sorting\n");
    
    // Cleanup
    free_stack(&a);
    free_array(args_array);
    return (0);
}