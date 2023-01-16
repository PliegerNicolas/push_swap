/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:45:55 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/16 18:51:32 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rule_reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->previous->next = NULL;
	last_node->previous = NULL;
	last_node->next = *stack;
	(*stack)->previous = last_node;
	*stack = last_node;
}

void	rule_rra(t_stack **stacks, t_bool print)
{
	if ((!stacks[A] || !stacks[A]->next))
		return ;
	rule_reverse_rotate(&stacks[A]);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rule_rrb(t_stack **stacks, t_bool print)
{
	if ((!stacks[B] || !stacks[B]->next))
		return ;
	rule_reverse_rotate(&stacks[B]);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rule_rrr(t_stack **stacks, t_bool print)
{
	if ((!stacks[A] || !stacks[A]->next) || (!stacks[B] || !stacks[B]->next))
		return ;
	rule_reverse_rotate(&stacks[A]);
	rule_reverse_rotate(&stacks[B]);
	if (print)
		ft_putendl_fd("rrr", 1);
}
