/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:55 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/08 17:56:48 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*buildstash(char *stash, char *buffer);
int		ft_strlen(char *s1);
char	*ft_strdup(char *src);
void	ft_strjoin(char *s1, char *s2, char **dest);
int		ft_scansatash(char *stash);
char	*extract_line(char *stash);
char	*sepstash(char *stash);
void	free_all(char *buffer, char **stash, char *line, int toggle);

#endif
