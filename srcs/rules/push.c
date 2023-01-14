/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:20:24 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/06 17:40:23 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rule_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (*dest)
	{
		temp->next = *dest;
		(temp->next)->previous = temp;
	}
	else
		temp->next = NULL;
	*dest = temp;
}

void	rule_pa(t_stack **stacks, t_bool print)
{
	if (!stacks[B])
		return ;
	rule_push(&stacks[B], &stacks[A]);
	if (print)
		ft_putendl_fd("pa", 1);
}

void	rule_pb(t_stack **stacks, t_bool print)
{
	if (!stacks[A])
		return ;
	rule_push(&stacks[A], &stacks[B]);
	if (print)
		ft_putendl_fd("pb", 1);
}
