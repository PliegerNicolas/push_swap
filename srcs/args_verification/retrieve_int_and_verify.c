/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_int_and_verify.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:24:55 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/16 19:05:09 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_bool	verify_duplicate(int *int_args, const size_t args_count)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < (args_count - 1))
	{
		j = i + 1;
		while (j < args_count)
		{
			if (int_args[i] == int_args[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

static t_bool	check_if_int(long long int llint)
{
	if (llint > MAX_INT || llint < MIN_INT)
	{
		ft_putendl_fd("Error. Given value exceeds integer type limit.", 2);
		return (FALSE);
	}
	return (TRUE);
}

static int	*retrieve_int(char **args, int *int_args)
{
	size_t			i;
	size_t			j;
	long long int	llint;

	i = 0;
	while (*args)
	{
		j = 0;
		while ((*args)[j])
		{
			llint = ft_index_atoi(*args + j, &j);
			if (!check_if_int(llint))
			{
				free(int_args);
				return (NULL);
			}
			else
				int_args[i++] = (int)llint;
			while ((*args)[j] == ' ')
				j++;
		}
		args++;
	}
	return (int_args);
}

int	*retrieve_int_and_verify(char **args, const size_t args_count)
{
	int		*int_args;

	int_args = malloc(args_count * sizeof(*int_args));
	if (!int_args)
		return (NULL);
	int_args = retrieve_int(args, int_args);
	if (!int_args)
		return (NULL);
	if (verify_duplicate(int_args, args_count))
	{
		free(int_args);
		ft_putendl_fd("Error. Duplicate value given.", 2);
		return (NULL);
	}
	return (int_args);
}
