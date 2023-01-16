/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:41:37 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/16 18:57:45 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*
#include <stdio.h>
void	display_stacks(t_stack **stacks, size_t args_count)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks[A];
	b = stacks[B];
	printf("\n");
	printf("=== STACKS ===\n");
	printf("%ld given arguments.\n", args_count);
	printf("Stack A :");
	while (a)
	{
		printf(" %d", a->data);
		a = a->next;
	}
	printf("\n");
	printf("Stack B :");
	while (b)
	{
		printf(" %d", b->data);
		b = b->next;
	}
	printf("\n");
	a = stacks[A];
	printf("\nFinal positions\n");
	printf("Stack A :");
	while (a)
	{
		printf(" %ld", a->f_pos);
		a = a->next;
	}
	printf("\n");
	b = stacks[B];
	printf("Stack B :");
	while (b)
	{
		printf(" %ld", b->f_pos);
		b = b->next;
	}
	printf("\n");
	printf("=== ====== ===\n");
	printf("\n");
}
*/

int	main(int argc, char **argv)
{
	t_stack		**stacks;
	size_t		args_count;

	if (!verify_given_args(argc, argv, &args_count))
		return (1);
	stacks = initialize_stacks(retrieve_int_and_verify(argv + 1,
				args_count), args_count);
	if (!stacks)
		return (1);
	sort_handler(stacks, args_count, TRUE);
	free_stacks(stacks);
	return (0);
}
