/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:57 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/20 09:51:02 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*  Standard Libraries  */ 
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/*  Custom Library  */
#include "../libft/libft.h"

/*  Node Structure Definition for Doubly Linked List */
typedef struct s_stack_node
{
    int                 value;
    struct s_stack_node *next;
    struct s_stack_node *prev;

}   t_stack_node;

/*  Stack Utilities (stack_utils.c)  */
t_stack_node    *create_node(int value);
t_stack_node    *find_last_node(t_stack_node *stack);
void            add_node_to_stack(t_stack_node **stack, t_stack_node *new_node);
int             stack_size(t_stack_node *stack);
bool            stack_is_sorted(t_stack_node *stack);

/*  Stack Operations 1 (stack_ops_1.c)  */
void            pa(t_stack_node **a, t_stack_node **b, bool print);
void            pb(t_stack_node **a, t_stack_node **b, bool print);
void            sa(t_stack_node **a, bool print);
void            sb(t_stack_node **b, bool print);

/*  Stack Operations 2 (stack_ops_2.c)  */
void            ra(t_stack_node **a, bool print);
void            rb(t_stack_node **b, bool print);
void            rra(t_stack_node **a, bool print);
void            rrb(t_stack_node **b, bool print);

/*  Stack Operations 3 (stack_ops_3.c)  */
void            ss(t_stack_node **a, t_stack_node **b, bool print);
void            rr(t_stack_node **a, t_stack_node **b, bool print);
void            rrr(t_stack_node **a, t_stack_node **b, bool print);

/*  Parsing (parsing/)  */
char            **parse_args(int argc, char **argv);
bool            is_valid_number(char *str);
bool            has_duplicate(t_stack_node *stack);
void            init_stack_a(t_stack_node **a, char **args_array);

/*  Utilities (utils/)  */
void            free_stack(t_stack_node **stack);
void            free_array(char **array);
void            error_exit(t_stack_node **a, char **args, char *messaage);

#endif