/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:23:08 by blvilarn          #+#    #+#             */
/*   Updated: 2023/02/24 19:19:36 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (int)1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer, int read_bytes);
int		is_nl_or_null(char *str, int read_bytes);
int		ft_strlen(char *str);
char	*deep_free(char **str);
void	*ft_calloc(size_t count, size_t size);

#endif