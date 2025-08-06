/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:55 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/06 16:37:32 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*buildstash(char *stash, char *buffer);
int 	ft_strlen(char *s1);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_scansatash(char *stash);
// char	*extract_line(char *stash);
// char	*update_stash(char *stash);
#endif
