/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:30:16 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/17 12:23:23 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static t_bool	rule_error_case(void)
{
	ft_putendl_fd("Error. Unvalid action read. ", 2);
	return (FALSE);
}

static t_bool	rule_apply(t_stack **stacks, char *instruction, t_bool print)
{
	if (!ft_strcmp(instruction, "pa\n"))
		rule_pa(stacks, print);
	else if (!ft_strcmp(instruction, "pb\n"))
		rule_pb(stacks, print);
	else if (!ft_strcmp(instruction, "sa\n"))
		rule_sa(stacks, print);
	else if (!ft_strcmp(instruction, "sb\n"))
		rule_sb(stacks, print);
	else if (!ft_strcmp(instruction, "ss\n"))
		rule_ss(stacks, print);
	else if (!ft_strcmp(instruction, "ra\n"))
		rule_ra(stacks, print);
	else if (!ft_strcmp(instruction, "rb\n"))
		rule_rb(stacks, print);
	else if (!ft_strcmp(instruction, "rr\n"))
		rule_rr(stacks, print);
	else if (!ft_strcmp(instruction, "rra\n"))
		rule_rra(stacks, print);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rule_rrb(stacks, print);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rule_rrr(stacks, print);
	else
		return (rule_error_case());
	return (TRUE);
}

t_bool	execute_rules(t_stack **stacks)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!rule_apply(stacks, line, FALSE))
		{
			free(line);
			free_stacks(stacks);
			return (FALSE);
		}
		free(line);
	}
	return (TRUE);
}
