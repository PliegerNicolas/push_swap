/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:09:46 by nplieger          #+#    #+#             */
/*   Updated: 2023/01/13 16:38:05 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);

char		*ft_set_scanner(char *scanner, size_t *cursor);
char		*ft_clear_scanner(char *scanner);
size_t		ft_strchr_index(const char *s, int c, size_t **nl_cursor,
				size_t rd_bytes);
void		ft_bufferjoin(char **scanner, const char *buffer, size_t rd_bytes);
char		*ft_truncate_scanner(char **scanner, char **new_line, size_t start);

#endif
