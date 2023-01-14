/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:56:52 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/08 22:28:57 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	fill_stack(t_stack **head, int data, size_t final_position)
{
	t_stack		*new_stack;

	new_stack = malloc(sizeof(*new_stack));
	if (!new_stack)
		return ;
	new_stack->data = data;
	new_stack->f_pos = final_position;
	new_stack->is_pivot = FALSE;
	new_stack->next = *head;
	new_stack->previous = NULL;
	if (*head)
		(*head)->previous = new_stack;
	*head = new_stack;
}

static t_stack	*initialize_stack_a(int *int_args, size_t args_count)
{
	t_stack		*stack;
	size_t		i;

	stack = NULL;
	i = 0;
	while (i < args_count)
		fill_stack(&stack, int_args[i++], 0);
	reverse_double_linked_stack(&stack);
	return (stack);
}

t_stack	**initialize_stacks(int *int_args, size_t args_count)
{
	t_stack		**stacks;

	if (!int_args)
		return (NULL);
	if (sort_int_args(int_args, args_count, FALSE))
	{
		free(int_args);
		return (NULL);
	}
	stacks = malloc(2 * sizeof(**stacks));
	if (!stacks)
	{
		free(int_args);
		return (NULL);
	}
	stacks[A] = initialize_stack_a(int_args, args_count);
	stacks[B] = NULL;
	set_final_positions(&stacks[A], int_args, args_count);
	free(int_args);
	return (stacks);
}
