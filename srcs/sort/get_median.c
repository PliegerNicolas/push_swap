/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:04:10 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/13 16:39:31 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(size_t *a, size_t *b)
{
	size_t	swapper;

	swapper = *a;
	*a = *b;
	*b = swapper;
}

static void	sort(size_t	**sorted_f_pos, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	min_index;

	i = 0;
	while (i < (len - 1))
	{
		min_index = i;
		j = i + 1;
		while (j < len)
		{
			if ((*sorted_f_pos)[j] < (*sorted_f_pos)[min_index])
			{
				min_index = j;
				continue ;
			}
			j++;
		}
		if (min_index != i)
			swap(&(*sorted_f_pos)[min_index], &(*sorted_f_pos)[i]);
		i++;
	}
}

t_bool	get_median(t_stack *stack, size_t args_count, size_t *median_f_pos)
{
	size_t	*sorted_f_pos;
	size_t	args_count_cpy;
	size_t	i;

	*median_f_pos = 0;
	sorted_f_pos = malloc(args_count * sizeof(*sorted_f_pos));
	if (!sorted_f_pos)
		return (0);
	i = 0;
	args_count_cpy = args_count;
	while (stack && args_count_cpy--)
	{
		sorted_f_pos[i++] = stack->f_pos;
		stack = stack->next;
	}
	sort(&sorted_f_pos, args_count);
	*median_f_pos = sorted_f_pos[args_count / 2];
	free(sorted_f_pos);
	return (1);
}
