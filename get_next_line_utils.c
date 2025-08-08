/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:00:19 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/08 13:15:34 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	dest = malloc (sizeof (char) * (len_src + 1));
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
	int		j;
	char	*dest;

	dest = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == (NULL))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		dest[j + ft_strlen(s1)] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*buildstash(char *stash, char *buffer)
{
	char	*temp;

	if (buffer == NULL)
		return (NULL);
	if (stash == NULL)
	{
		return (ft_strdup(buffer));
	}
	temp = ft_strdup(stash);
	free(stash);
	if (temp == NULL)
		return (NULL);
	stash = ft_strjoin(temp, buffer);
	free(temp);
	return (stash);
}
