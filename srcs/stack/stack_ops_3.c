/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <nenerosa@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:11:56 by bbeceiro          #+#    #+#             */
/*   Updated: 2025/08/26 16:14:47 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_stack_node **a, t_stack_node **b, bool print)
{
    sa(a, false);
    sb(b, false);
    if (print)
        printf("ss\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    ra(a, false);
    rb(b, false);
    if (print)
        printf("rr\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rra(a, false);
    rrb(b, false);
    if (print)
        printf("rrr\n");
}