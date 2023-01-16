/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_given_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:05:13 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/16 18:47:53 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_bool	validate_argument(char *arg, size_t *args_count)
{
	size_t		i;
	t_bool		first_value;

	i = 0;
	first_value = TRUE;
	while (arg[i])
	{
		if (!first_value && arg[i] != ' ')
			return (1);
		while (arg[i] == ' ')
			i++;
		if (!arg[i])
			continue ;
		if (arg[i] == '+' || arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]))
			return (1);
		while (ft_isdigit(arg[i]))
			i++;
		(*args_count)++;
		first_value = FALSE;
	}
	return (0);
}

static size_t	count_args(char **args)
{
	size_t	args_count;

	args_count = 0;
	while (*args)
	{
		if (validate_argument(*args, &args_count))
			return (0);
		args++;
	}
	return (args_count);
}

t_bool	verify_given_args(int argc, char **argv, size_t *args_count)
{
	if (argc < 2)
		return (0);
	*args_count = count_args(argv + 1);
	if (*args_count < 2)
	{
		if (*args_count == 0)
			ft_putendl_fd("Error. Format should be [int] [int] [...].", 2);
		return (0);
	}
	return (1);
}
