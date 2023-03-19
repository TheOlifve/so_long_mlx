/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:23:38 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/17 14:43:19 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strrncmp(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 3;
	s2 = ".ber";
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	while (j > -1)
	{
		i--;
		if (s1[i] != s2[j])
			return (0);
		j--;
	}
	return (1);
}
