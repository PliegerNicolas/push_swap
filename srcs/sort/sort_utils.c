/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:50:32 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/12 01:56:28 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_bool	stack_is_sorted(t_stack *stack, size_t len)
{
	size_t	min_f_pos;

	if (!stack)
		return (FALSE);
	if (!stack->next)
		return (TRUE);
	min_f_pos = stack->f_pos;
	stack = stack->next;
	while (stack && len--)
	{
		if (min_f_pos > stack->f_pos)
			return (FALSE);
		min_f_pos = stack->f_pos;
		stack = stack->next;
	}
	return (TRUE);
}

t_bool	stack_is_reverse_sorted(t_stack *stack, size_t len)
{
	size_t	max_f_pos;

	if (!stack)
		return (FALSE);
	if (!stack->next)
		return (TRUE);
	max_f_pos = stack->f_pos;
	stack = stack->next;
	while (stack && len--)
	{
		if (max_f_pos < stack->f_pos)
			return (FALSE);
		max_f_pos = stack->f_pos;
		stack = stack->next;
	}
	return (TRUE);
}

size_t	stack_len(t_stack *stack)
{
	size_t	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
