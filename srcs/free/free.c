/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:25:19 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/08 21:26:13 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack		*current;
	t_stack		*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_stacks(t_stack **stacks)
{
	size_t		i;

	i = 0;
	while (stacks[i])
	{
		free_stack(stacks[i]);
		stacks[i++] = NULL;
	}
	free(stacks);
	stacks = NULL;
}
