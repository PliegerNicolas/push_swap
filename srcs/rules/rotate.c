/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:16:00 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/06 19:01:02 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rule_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*second_node;

	if (!*stack)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	second_node = (*stack)->next;
	second_node->previous = NULL;
	(*stack)->next = NULL;
	(*stack)->previous = last_node;
	last_node->next = *stack;
	*stack = second_node;
}

void	rule_ra(t_stack **stacks, t_bool print)
{
	if (!stacks[A])
		return ;
	if (!stacks[A]->next)
		return ;
	rule_rotate(&stacks[A]);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rule_rb(t_stack **stacks, t_bool print)
{
	if (!stacks[B])
		return ;
	if (!stacks[B]->next)
		return ;
	rule_rotate(&stacks[B]);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rule_rr(t_stack **stacks, t_bool print)
{
	if (!stacks[A] && !stacks[B])
		return ;
	rule_rotate(&stacks[A]);
	rule_rotate(&stacks[B]);
	if (print)
		ft_putendl_fd("rr", 1);
}
