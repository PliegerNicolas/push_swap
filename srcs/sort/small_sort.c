/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:24:16 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/14 02:31:09 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* s = stacks, t = target */
static void	simple_sort_three(t_stack **s, t_bool print, t_bool t)
{
	if (s[t]->f_pos < s[t]->next->f_pos)
	{
		if (s[t]->next->f_pos > s[t]->next->next->f_pos)
			select_target_method(s, t, print, rule_rra, rule_rrb);
		if (s[t]->f_pos > s[t]->next->f_pos)
			select_target_method(s, t, print, rule_sa, rule_sb);
	}
	else
	{
		if (s[t]->f_pos < s[t]->next->next->f_pos)
		{
			select_target_method(s, t, print, rule_sa, rule_sb);
			return ;
		}
		select_target_method(s, t, print, rule_ra, rule_rb);
		if (s[t]->f_pos > s[t]->next->f_pos)
			select_target_method(s, t, print, rule_sa, rule_sb);
	}
}

/* s = stacks, t = target */
static void	complexe_sort_three(t_stack **s, size_t args_count, t_bool print,
	t_bool t)
{
	while (args_count != 3 || !(s[t]->f_pos < s[t]->next->f_pos
			&& s[t]->next->f_pos < s[t]->next->next->f_pos))
	{
		if (args_count == 3 && s[t]->f_pos > s[t]->next->f_pos
			&& s[t]->next->next)
			select_target_method(s, t, print, rule_sa, rule_sb);
		else if (args_count == 3 && !(s[t]->next->next->f_pos > s[t]->f_pos
				&& s[t]->next->next->f_pos > s[t]->next->f_pos))
		{
			select_target_method(s, !t, print, rule_pa, rule_pb);
			args_count--;
		}
		else if (s[t]->f_pos > s[t]->next->f_pos)
			select_target_method(s, t, print, rule_sa, rule_sb);
		else if (args_count++)
			select_target_method(s, t, print, rule_pa, rule_pb);
	}
}

/* s = stacks, t = target */
void	sort_three(t_stack **s, size_t args_count, t_bool print, t_bool t)
{
	if ((args_count == 3) && (stack_len(s[t]) == 3))
		simple_sort_three(s, print, t);
	else if (args_count == 2)
		select_target_method(s, t, print, rule_sa, rule_sb);
	else if (args_count == 3)
		complexe_sort_three(s, args_count, print, t);
}

/* s = stacks, t = target */
static void	complexe_sort_three_and_push(t_stack **s, size_t args_count,
	t_bool print, t_bool t)
{
	while (args_count || !(s[!t]->f_pos < s[!t]->next->f_pos
			&& s[!t]->next->f_pos < s[!t]->next->next->f_pos))
	{
		if (args_count == 1 && s[!t]->f_pos > s[!t]->next->f_pos)
			select_target_method(s, !t, print, rule_sa, rule_sb);
		else if (args_count == 1 || (args_count >= 2
				&& s[t]->f_pos > s[t]->next->f_pos)
			|| (args_count == 3 && s[t]->f_pos > s[t]->next->next->f_pos))
		{
			select_target_method(s, !t, print, rule_pa, rule_pb);
			args_count--;
		}
		else
			select_target_method(s, t, print, rule_sa, rule_sb);
	}
}

/* s = stacks, t = target */
void	sort_three_and_push(t_stack **s, size_t args_count, t_bool print,
	t_bool t)
{
	if (args_count == 1)
		select_target_method(s, !t, print, rule_pa, rule_pb);
	else if (args_count == 2)
	{
		if (s[t]->f_pos < s[t]->next->f_pos)
			select_target_method(s, t, print, rule_sa, rule_sb);
		select_target_method(s, !t, print, rule_pa, rule_pb);
		select_target_method(s, !t, print, rule_pa, rule_pb);
	}
	else if (args_count == 3)
		complexe_sort_three_and_push(s, args_count, print, t);
}
