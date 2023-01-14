/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:37:20 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/06 23:49:17 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_bool	sort_int_args(int *int_args, const size_t args_count, t_bool sorting)
{
	size_t		i;
	size_t		j;
	size_t		min_index;

	i = 0;
	while (i < (args_count - 1))
	{
		min_index = i;
		j = i + 1;
		while (j < args_count)
		{
			if (int_args[j] < int_args[min_index])
			{
				if (!sorting)
					return (FALSE);
				min_index = j;
				continue ;
			}
			j++;
		}
		if (min_index != i)
			ft_swap(&int_args[min_index], &int_args[i]);
		i++;
	}
	return (TRUE);
}
