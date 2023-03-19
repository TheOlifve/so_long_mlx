/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:36:16 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/18 21:06:22 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_add(t_list *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"img/floor.xpm", &i, &j);
	game->walls = mlx_xpm_file_to_image(game->mlx,
			"img/walls.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"img/exit.xpm", &i, &j);
}

void	map_render(t_list *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->win_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->walls, j * 64, i * 64);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->floor, j * 64, i * 64);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
