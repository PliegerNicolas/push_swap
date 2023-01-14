/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_target_method.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:30:11 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/14 02:30:23 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	select_target_method(t_stack **stacks, const int target,
	const t_bool print, void func_a (t_stack**, t_bool),
	void func_b (t_stack**, t_bool))
{
	if (target == A)
		func_a(stacks, print);
	if (target == B)
		func_b(stacks, print);
}
