/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:31:51 by nherimam          #+#    #+#             */
/*   Updated: 2025/01/08 22:20:09 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *old, char *str)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free (old);
	return (new);
}

char	*lft_strdup(const char *s)
{
	char	*now;
	int		len;

	len = ft_strlen(s);
	now = (char *)malloc (sizeof (char) * (len + 1));
	if (now == NULL)
		return (NULL);
	ft_strlcpy(now, s, (len + 1));
	return (now);
}

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (!dst && !src)
		return (0);
	if (size > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < size - 1)
		{
			*(dst + i) = *(src + i);
			i ++;
		}
		*(dst + i) = '\0';
	}
	return (len);
}
