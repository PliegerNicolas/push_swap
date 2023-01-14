/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_double_linked_stack.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:15:14 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/06 13:31:25 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_double_linked_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*temp;

	current = *head;
	temp = NULL;
	while (current)
	{
		temp = current->previous;
		current->previous = current->next;
		current->next = temp;
		current = current->previous;
	}
	if (temp)
		*head = temp->previous;
}
