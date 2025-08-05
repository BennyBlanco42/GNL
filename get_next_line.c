/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:28:04 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/05 15:13:23 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE	20
// PLusieur fonctions necessaire  
char	*get_next_line(int fd)
{
	static char *stash = NULL;
	char	*buffer;

	if (fd == -1)
		return(0);

	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		// if (ft_strlcpy(stash, buffer, BUFFER_SIZE) == -1)
		// 	return (-1);

		
		
	}
	return(0);
	
}
// gerer le cas ou read return -1 => erreur de lecture => stop 
