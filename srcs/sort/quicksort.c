/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:43:06 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/14 04:19:41 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_handler(t_stack **stacks, size_t args_count, t_bool print)
{
	if (args_count <= 3)
		sort_three(stacks, args_count, print, A);
	else
		quicksort_a(stacks, args_count, print);
}

static t_bool	quicksort_a_fork(t_stack **stacks, size_t *args_count,
	t_bool print)
{
	if (stack_is_sorted(stacks[A], *args_count))
		return (1);
	if (*args_count <= 3)
	{
		sort_three(stacks, *args_count, print, A);
		return (1);
	}
	return (0);
}

t_bool	quicksort_a(t_stack **stacks, size_t args_count, t_bool print)
{
	size_t	median;
	size_t	nb_elem;
	size_t	pushed_under;

	nb_elem = args_count;
	if (quicksort_a_fork(stacks, &args_count, print))
		return (1);
	pushed_under = 0;
	if (!get_median(stacks[A], args_count, &median))
		return (0);
	while (args_count != nb_elem / 2 + nb_elem % 2)
	{
		if (stacks[A]->f_pos < median && (args_count--))
			rule_pb(stacks, TRUE);
		else if (++pushed_under)
			rule_ra(stacks, TRUE);
	}
	while (nb_elem / 2 + nb_elem % 2 != stack_len(stacks[A]) && pushed_under--)
		rule_rra(stacks, TRUE);
	return (quicksort_a(stacks, nb_elem / 2 + nb_elem % 2, print)
		&& quicksort_b(stacks, nb_elem / 2, print));
	return (1);
}

static t_bool	quicksort_b_fork(t_stack **stacks, size_t *args_count,
	t_bool print)
{
	if (stack_is_reverse_sorted(stacks[B], *args_count))
	{
		while (*args_count)
		{
			rule_pa(stacks, print);
			(*args_count)--;
		}
	}
	if (*args_count <= 3)
	{
		sort_three_and_push(stacks, *args_count, print, B);
		return (1);
	}
	return (0);
}

t_bool	quicksort_b(t_stack **stacks, size_t args_count, t_bool print)
{
	size_t	median;
	size_t	nb_elem;
	size_t	pushed_under;

	pushed_under = 0;
	if (quicksort_b_fork(stacks, &args_count, print))
		return (1);
	nb_elem = args_count;
	if (!get_median(stacks[B], args_count, &median))
		return (0);
	while (args_count != nb_elem / 2)
	{
		if (stacks[B]->f_pos >= median && args_count--)
			rule_pa(stacks, TRUE);
		else if (++pushed_under)
			rule_rb(stacks, TRUE);
	}
	while (nb_elem / 2 != stack_len(stacks[B]) && pushed_under--)
		rule_rrb(stacks, TRUE);
	return (quicksort_a(stacks, nb_elem / 2 + nb_elem % 2, print)
		&& quicksort_b(stacks, nb_elem / 2, print));
	return (1);
}
