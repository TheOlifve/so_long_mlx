/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:35:30 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/18 19:37:26 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_valid(t_list *game, char **map, int i, int j)
{
	char	s[1];

	s[0] = map[0][0];
	while (map[++i])
	{
		while (map[i][j])
		{
			s[0] = map[i][j];
			if (map[i][j] == 'E')
			{
				game->door_x = i;
				game->door_y = j;
			}
			if (s[0] == '0' || s[0] == '1' || s[0] == 'P' || s[0] == '\n'
				|| s[0] == 'C' || s[0] == 'E' || s[0] == 'N')
				j++;
			else
				return (0);
		}
		j = 0;
	}
	return (1);
}

int	map_components(char **map, int i, int j, t_list *game)
{
	int	sym[3];

	sym[0] = 1;
	sym[1] = 1;
	sym[2] = 1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				game->p_x = i;
				game->p_y = j;
				sym[0]++;
			}
			else if (map[i][j] == 'C')
				game->coins = sym[1]++;
			else if (map[i][j] == 'E')
				sym[2]++;
		}
		j = -1;
	}
	if (sym[0] != 2 || sym[1] < 2 || sym[2] != 2)
		return (0);
	return (1);
}

int	map_walls(char **map, int i, int j)
{
	while (map && map[0][++i])
	{
		if (map[0][i] != '1')
			return (0);
	}
	if (!map_line_len(map, i))
		return (0);
	i--;
	while (map && map[j])
	{
		if (map[j][0] != '1' || map[j][i] != '1')
			return (0);
		j++;
	}
	j--;
	i = -1;
	while (map && map[j][++i])
	{
		if (map[j][i] != '1')
			return (0);
	}
	return (1);
}

int	check_map(char **map, t_list *game)
{
	if (!map_walls(map, -1, 0))
		return (0);
	if (!map_valid(game, map, -1, 0))
		return (0);
	if (!map_components(map, -1, -1, game))
		return (0);
	return (1);
}

int	check_all(int argc, char **argv, t_list *game)
{
	char	**map;

	if (argc != 2)
		return (ft_error_print("ERROR - Wrong number of parameters"));
	if (!ft_strrncmp(argv[1]))
		return (ft_error_print("ERROR - Wrong file type (should be .ber)"));
	map = map_r(argv[1]);
	if (!map || !check_map(map, game))
		return (ft_error_print("ERROR - Wrong map"));
	//if (!logic(game))
	//	return (ft_error_print("ERROR - Wrong map"));
	game->coins = game->coins - 1;
	game->map = map;
	return (1);
}
