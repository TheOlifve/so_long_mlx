/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:55:52 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/27 22:56:21 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	door(t_list *game)
{
	int	i;
	int	j;

	game->door = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c.xpm", &i, &j);
	game->door1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_o1.xpm", &i, &j);
	game->door2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c2.xpm", &i, &j);
	game->door3 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c3.xpm", &i, &j);
	game->door4 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c4.xpm", &i, &j);
	game->door5 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c5.xpm", &i, &j);
	game->door6 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c6.xpm", &i, &j);
	game->door7 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_c.xpm", &i, &j);
}
