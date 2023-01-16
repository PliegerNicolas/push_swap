/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:09:31 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/16 18:58:02 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static t_bool	b_is_empty(t_stack **stacks)
{
	if (stack_len(stacks[B]))
	{
		ft_putendl_fd("KO", 1);
		free_stacks(stacks);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	is_sorted_after_rules(t_stack **stacks, const size_t args_count)
{
	if (stack_is_sorted(stacks[A], args_count))
	{
		ft_putendl_fd("OK", 1);
		free_stacks(stacks);
		return (TRUE);
	}
	else
	{
		ft_putendl_fd("KO", 1);
		free_stacks(stacks);
		return (FALSE);
	}
}

int	main(int argc, char **argv)
{
	t_stack		**stacks;
	size_t		args_count;

	if (!verify_given_args(argc, argv, &args_count))
		return (1);
	stacks = initialize_stacks_checker
		(retrieve_int_and_verify(argv + 1, args_count), args_count);
	if (!stacks)
		return (1);
	if (!b_is_empty(stacks))
		return (1);
	if (!execute_rules(stacks))
		return (1);
	if (!b_is_empty(stacks))
		return (1);
	if (!is_sorted_after_rules(stacks, args_count))
		return (1);
	return (0);
}
