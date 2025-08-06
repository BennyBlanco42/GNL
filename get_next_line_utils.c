/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:00:19 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/06 16:44:53 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strchr => pour chercher dans la resevre si il y'a un \n 
// strdup => malloc ?
#include "get_next_line.h"


int	ft_strlen(char *s1)
{	
	int	i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len_src;

	len_src = ft_strlen(src);
	dest = malloc (sizeof (char) * len_src + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	dest = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == (NULL))
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= ft_strlen(s2))
	{
		dest[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	dest[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	return (dest);
}


char	*buildstash(char *stash, char *buffer)
{
	char *temp;
	if (stash == NULL)
	{
		stash = ft_strdup(buffer);
	}
	temp = ft_strdup(stash);
	stash = ft_strjoin(temp, buffer);
	free(temp);
	free(buffer);
	return (stash);

	
}

//besoin d4un fct qui seprqre stash a partir du \n