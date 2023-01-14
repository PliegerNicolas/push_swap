/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:13:39 by nplieger          #+#    #+#             */
/*   Updated: 2023/01/13 03:41:52 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* Fills the buffer */
/* Nullifies usecase where rd_bytes = -1*/
int	ft_fill_buffer(int fd, char **buffer)
{
	int	rd_bytes;

	rd_bytes = read(fd, *buffer, BUFFER_SIZE);
	if (rd_bytes < 0)
		return (0);
	return (rd_bytes);
}

/* Malloc'd buffer to accept values above heap limits. */
/* 1 - Initialize all buffer values as '\0' */
/* 2 - fill buffer and set cursor until \n found.*/
/* Meanwhile, loop through buffers until '\n' found and join to scanner. */
char	*ft_scan_file(int fd, char *scanner, size_t *nl_cursor)
{
	char		*buffer;
	int			rd_bytes;

	if (!scanner)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (NULL);
	rd_bytes = BUFFER_SIZE + 1;
	while (rd_bytes)
		*(buffer + --rd_bytes) = '\0';
	rd_bytes = ft_fill_buffer(fd, &buffer);
	if (rd_bytes > 0)
		ft_bufferjoin(&scanner, buffer, rd_bytes);
	while ((ft_strchr_index(buffer, '\n', &nl_cursor, rd_bytes)
			== BUFFER_SIZE) && (rd_bytes > 0))
	{
		rd_bytes = ft_fill_buffer(fd, &buffer);
		if (!buffer)
			return (NULL);
		ft_bufferjoin(&scanner, buffer, rd_bytes);
	}
	free(buffer);
	return (scanner);
}

/* Verifies if previous scanner contains \n */
/* Prevents useless buffer reads. */
int	ft_contains_nl(char *scanner, size_t nl_cursor)
{
	if (nl_cursor > 0)
		if (scanner[nl_cursor - 1] == '\n')
			return (1);
	return (0);
}

/* Retrieve the line from scanner and truncates scanner accordingly */
char	*ft_retrieve_line(char **scanner, size_t *nl_cursor)
{
	char		*new_line;
	size_t		i;

	if (!*nl_cursor)
		return (NULL);
	new_line = malloc((*nl_cursor + 1) * sizeof(*new_line));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < *nl_cursor)
	{
		new_line[i] = (*scanner)[i];
		i++;
	}
	new_line[i] = '\0';
	*scanner = ft_truncate_scanner(scanner, &new_line, i);
	return (new_line);
}

/* 4 * kibibyte = 1024 * 4 bytes */
char	*get_next_line(int fd)
{
	static char		*scanner[4096];
	char			*line;
	size_t			overflow_len;

	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 4096))
		return (NULL);
	scanner[fd] = ft_set_scanner(scanner[fd], &overflow_len);
	if (!ft_contains_nl(scanner[fd], overflow_len))
		scanner[fd] = ft_scan_file(fd, scanner[fd], &overflow_len);
	if (!overflow_len && scanner[fd][overflow_len] == '\n')
		overflow_len++;
	line = ft_retrieve_line(&(scanner[fd]), &overflow_len);
	scanner[fd] = ft_clear_scanner(scanner[fd]);
	return (line);
}
