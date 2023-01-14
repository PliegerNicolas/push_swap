/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_int_and_verify_duplicate.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:24:55 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/06 17:55:49 by nicolas          ###   ########.fr       */
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

static int	*retrieve_int(char **args, int *int_args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*args)
	{
		j = 0;
		while ((*args)[j])
		{
			int_args[i++] = ft_index_atoi(*args + j, &j);
			while ((*args)[j] == ' ')
				j++;
		}
		args++;
	}
	return (int_args);
}

int	*retrieve_int_and_verify_duplicate(char **args, const size_t args_count)
{
	int		*int_args;

	int_args = malloc(args_count * sizeof(*int_args));
	if (!int_args)
		return (NULL);
	int_args = retrieve_int(args, int_args);
	if (verify_duplicate(int_args, args_count))
	{
		free(int_args);
		ft_putendl_fd("Error. Duplicate value given.", 2);
		return (NULL);
	}
	return (int_args);
}
