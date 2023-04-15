/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:31:53 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/18 19:54:00 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_r(char *file)
{
	char	*temp;
	char	*temp1;
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	temp = ft_strdup("");
	temp1 = ft_strdup("");
	while (temp1)
	{	
		temp1 = get_next_line(fd);
		temp = ft_strjoin(temp, temp1);
	}
	map = ft_split(temp, '\n');
	close(fd);
	if (!map[0])
		return (NULL);
	return (map);
}
