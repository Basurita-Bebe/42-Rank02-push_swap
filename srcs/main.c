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

// #define TESTING 1

#ifdef TESTING
    #include "testing.h"
#endif

int main(int argc, char **argv)
{
    #ifdef TESTING
        // run test functions
        printf("===== Starting All Tests =====\n\n");

        test_normalization();
        printf("\n");

        test_radix_sort();
        printf("\n");

        printf("===== All Tests Complited =====");
        return (0);
    #else
        // Main function
        t_stack_node    *a;
        t_stack_node    *b;
        char            **args_array;
        int             size;

        a = NULL;
        b = NULL;
        if (argc == 1)
            return (0);
        // 1. Parse arguments
        args_array = parse_args(argc, argv);
        if (args_array == NULL)
            error_exit(&a, NULL, "Parsing failed\n");
        // 2. Validate and build stack a
        init_stack_a(&a, args_array);
        // 3. Check if already sorted
        if (stack_is_sorted(a))
        {
            free_stack(&a);
            free_array(args_array);
            return (0);
        }
        // 4. Choose sorting algorithm based on size
        size = stack_size(a);
        if (size <= 5)
            small_sort(&a, &b);
        else
            big_sort(&a, &b);
        // 5. Clean up
        free_stack(&a);
        free_array(args_array);
        return (0);
    #endif
}