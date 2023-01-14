/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:40:23 by nplieger          #+#    #+#             */
/*   Updated: 2023/01/13 03:42:03 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* Set empty scanner if doesn't exist. */
/* Stores length of scanner in overflow_len ; By default 0. */
/* On error, set scanner as NULL. */
char	*ft_set_scanner(char *scanner, size_t *overflow_len)
{
	int		found_nl;

	if (!scanner)
	{
		scanner = malloc(1 * sizeof(*scanner));
		if (!scanner)
			return (NULL);
		scanner[0] = '\0';
	}
	*overflow_len = 0;
	found_nl = 0;
	while (scanner[*overflow_len] && !found_nl)
	{
		if (scanner[*overflow_len] == '\n')
			found_nl = 1;
		(*overflow_len)++;
	}
	return (scanner);
}

/* if scanner is empty, free it and return NULL. */
char	*ft_clear_scanner(char *scanner)
{
	if (scanner && !scanner[0])
	{
		free(scanner);
		return (NULL);
	}
	return (scanner);
}

/* Return index of searched char (nl) */
/* Returns BUFFER_SIZE + 1 to exist i % BUFFER_SIZE condition. */
/* Else retursn read_bytes. Meanwhile nl_cursor is updated. */
size_t	ft_strchr_index(const char *s, int c, size_t **nl_cursor,
			size_t rd_bytes)
{
	size_t		i;

	i = 0;
	if (!s || !rd_bytes)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			**nl_cursor += i + 1;
			return (BUFFER_SIZE + 1);
		}
		i++;
	}
	**nl_cursor += rd_bytes;
	return (rd_bytes);
}

/* Join buffer to previous scanner. */
void	ft_bufferjoin(char **scanner, const char *buffer, size_t rd_bytes)
{
	char		*new_scanner;
	size_t		prev_scan_len;
	size_t		i;

	prev_scan_len = 0;
	while ((*scanner)[prev_scan_len])
		prev_scan_len++;
	new_scanner = malloc((prev_scan_len + rd_bytes + 1) * sizeof(*new_scanner));
	if (!new_scanner)
		return ;
	i = 0;
	while (i < prev_scan_len)
	{
		new_scanner[i] = (*scanner)[i];
		i++;
	}
	i = 0;
	while (i < rd_bytes)
	{
		new_scanner[prev_scan_len + i] = buffer[i];
		i++;
	}
	new_scanner[prev_scan_len + i] = '\0';
	free(*scanner);
	*scanner = new_scanner;
}

/* Shortens scanner after line has been recuperated. */
char	*ft_truncate_scanner(char **scanner, char **new_line, size_t start)
{
	char		*new_scanner;
	size_t		i;

	(*scanner) += start;
	i = 0;
	while ((*scanner)[i])
		i++;
	new_scanner = malloc((i + 1) * sizeof(*new_scanner));
	if (!new_scanner)
	{
		free(*new_line);
		return (NULL);
	}
	i = 0;
	while ((*scanner)[i])
	{
		new_scanner[i] = (*scanner)[i];
		i++;
	}
	new_scanner[i] = '\0';
	free((*scanner) - start);
	*scanner = new_scanner;
	return (*scanner);
}
