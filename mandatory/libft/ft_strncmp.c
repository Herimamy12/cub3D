/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herirand <herirand@student.42Antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:19:54 by herirand          #+#    #+#             */
/*   Updated: 2024/11/19 10:17:52 by herirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && !((s1[i] == s2[i]) && !s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return (0);
}

int	lft_strcmp(char *s1, char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *nb)
{
	char	*nbr;
	int		res;
	int		i;

	if (!nb)
		return (-1);
	i = 0;
	res = 0;
	nbr = (char *)nb;
	while ((nbr[i] && nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i ++;
	if (nbr[i] == '-' || nbr[i] == '+')
		return (0);
	while (ft_isdigit(nbr[i]))
	{
		res = (res * 10) + (nbr[i] - 48);
		i ++;
	}
	return (res);
}
