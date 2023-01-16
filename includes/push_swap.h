/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:21:32 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/16 19:01:08 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************** */
/* * INCLUDES							* */
/* ************************************** */

# include "stack.h"
# include <unistd.h>
# include <stdlib.h>

/* ************************************** */
/* * TYPEDEFS							* */
/* ************************************** */

# define A 0
# define B 1
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* ************************************** */
/* * FUNCTIONS							* */
/* ************************************** */

/* ARGS_VERIFICATION */

t_bool			verify_given_args(int argc, char **argv, size_t *args_count);
int				*retrieve_int_and_verify(char **args, const size_t args_count);

/* INITIALIZE */

t_stack			**initialize_stacks(int *int_args, size_t args_count);
void			reverse_double_linked_stack(t_stack **head);
void			set_final_positions(t_stack **stack, int *int_args,
					size_t args_count);
t_bool			sort_int_args(int *int_args, const size_t args_count,
					t_bool sorting);
/* SORT */

void			sort_handler(t_stack **stacks, size_t args_count, t_bool print);
t_bool			quicksort_a(t_stack **stacks, size_t args_count, t_bool print);
t_bool			quicksort_b(t_stack **stacks, size_t args_count, t_bool print);
t_bool			get_median(t_stack *stack, size_t args_count,
					size_t *median_f_pos);
void			sort_three(t_stack **s, size_t args_count, t_bool print,
					t_bool t);
void			sort_three_and_push(t_stack **stacks, size_t args_count,
					t_bool print, t_bool target);
void			select_target_method(t_stack **stacks, const int target,
					const t_bool print, void func_a (t_stack**, t_bool),
					void func_b (t_stack**, t_bool));

/* QUICKSORT UTILS */

t_bool			stack_is_sorted(t_stack *stack, size_t len);
t_bool			stack_is_reverse_sorted(t_stack *stack, size_t len);
size_t			stack_len(t_stack *stack);

/* UTILS */

void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

int				ft_isdigit(int c);
long long int	ft_index_atoi(const char *nptr, size_t *index);
void			ft_swap(int *a, int *b);

/* FREE */

void			free_stack(t_stack *stack);
void			free_stacks(t_stack **stacks);

#endif
