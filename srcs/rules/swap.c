/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:36:46 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/13 16:37:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rule_swap(t_stack **stack)
{
	(*stack)->previous = (*stack)->next;
	(*stack)->next = (*stack)->previous->next;
	if ((*stack)->previous->next)
		(*stack)->previous->next->previous = *stack;
	(*stack)->previous->next = (*stack);
	(*stack)->previous->previous = NULL;
	(*stack) = (*stack)->previous;
}

void	rule_sa(t_stack **stacks, t_bool print)
{
	if (!stacks[A])
		return ;
	rule_swap(&stacks[A]);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	rule_sb(t_stack **stacks, t_bool print)
{
	if (!stacks[B])
		return ;
	rule_swap(&stacks[B]);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	rule_ss(t_stack **stacks, t_bool print)
{
	if (!stacks[A] || !stacks[B])
		return ;
	rule_swap(&stacks[A]);
	rule_swap(&stacks[B]);
	if (print)
		ft_putendl_fd("ss", 1);
}
