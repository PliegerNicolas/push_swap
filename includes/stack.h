/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:21:32 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/08 22:28:35 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

/* ************************************** */
/* * INCLUDES							* */
/* ************************************** */

# include <stddef.h>

/* ************************************** */
/* * TYPEDEFS							* */
/* ************************************** */

# define FALSE 0
# define TRUE 1

typedef int	t_bool;

typedef struct s_stack
{
	int					data;
	size_t				f_pos;
	t_bool				is_pivot;
	struct s_stack		*previous;
	struct s_stack		*next;
}	t_stack;

/* ************************************** */
/* * FUNCTIONS							* */
/* ************************************** */

/* SWAP */

void		rule_sa(t_stack **stacks, t_bool print);
void		rule_sb(t_stack **stacks, t_bool print);
void		rule_ss(t_stack **stacks, t_bool print);

/* PUSH */

void		rule_pa(t_stack **stacks, t_bool print);
void		rule_pb(t_stack **stacks, t_bool print);

/* ROTATE */

void		rule_ra(t_stack **stacks, t_bool print);
void		rule_rb(t_stack **stacks, t_bool print);
void		rule_rr(t_stack **stacks, t_bool print);

/* REVERSE_ROTATE */

void		rule_rra(t_stack **stacks, t_bool print);
void		rule_rrb(t_stack **stacks, t_bool print);
void		rule_rrr(t_stack **stacks, t_bool print);

#endif
