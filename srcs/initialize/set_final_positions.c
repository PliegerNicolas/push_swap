/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_final_positions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:59:31 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/06 22:56:33 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_final_positions(t_stack **head, int *int_args, size_t args_count)
{
	t_stack		*current;
	size_t		i;

	if (!head || !int_args)
		return ;
	current = *head;
	sort_int_args(int_args, args_count, TRUE);
	while (current)
	{
		i = 0;
		while (int_args[i] != current->data)
			i++;
		current->f_pos = i;
		current = current->next;
	}
}
