/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:44:56 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char **duplicate_argv(int argc, char **argv)
{
    char    **args_array;
    int     i;

    // Allocate memory for the array (argc - 1 elements + NULL terminator)
    args_array = malloc(sizeof(char *) * argc);
    if (args_array == NULL)
        return (NULL);
    // Copy each argument from argv[1] to argv[argc - 1]
    i = 1;
    while (i < argc)
    {
        args_array[i - 1] = ft_strdup(argv[i]);
        if (args_array[i - 1] == NULL)
        {
            // If allocation fails free whats allocated so far
            free_array(args_array);
            return (NULL);
        }
        i++;
    }
    args_array[i - 1] = NULL;
    return (args_array);
}

// Handle both input formats and return a uniform array of strings
char    **parse_args(int argc, char **argv)
{
    char    **args_array;

    if (argc < 2)
        return (NULL);
    if (argc == 2)
    {
        // Split the single argument by spaces
        args_array = ft_split(argv[1], ' ');
    }
    else
    {
        // Duplicate multiple arguments
        args_array = duplicate_argv(argc, argv);
    }
    return (args_array);
}

