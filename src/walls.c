/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:36:16 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/22 18:06:03 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mb(t_list *game, int i, int j)
{
	int	x;
	int	y;

	x = game->win_height - 1;
	y = game->win_width - 1;
	while (++i < game->win_height)
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (i != x && i != 0 && j != 0 && j != y
				&& game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->wall_01, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->h1, j * 64, i * 64);
			else if (game->map[i][j] == 'N')
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, game->flw, j * 64, i * 64);
		}
	}
}

void	wall_add(t_list *game)
{
	int	i;
	int	j;

	game->wall_01 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_01.xpm", &i, &j);
	game->wall_d = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_d.xpm", &i, &j);
	game->wall_dl = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_dl.xpm", &i, &j);
	game->wall_dr = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_dr.xpm", &i, &j);
	game->wall_l = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_l.xpm", &i, &j);
	game->wall_r = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_r.xpm", &i, &j);
	game->wall_u = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_u.xpm", &i, &j);
	game->wall_ul = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_ul.xpm", &i, &j);
	game->wall_ur = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/wall_ur.xpm", &i, &j);
}

void	wall_render(t_list *game, int i, int j, int k)
{
	girl_render(game);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->wall_ul, 0, 0);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->wall_dr, j * 64, i * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->wall_dl, 0, i * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->wall_ur, j * 64, 0);
	while (++k < j)
	{
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall_d, k * 64, i * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall_u, k * 64, 0);
	}
	k = 0;
	while (++k < i)
	{
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall_r, j * 64, k * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall_l, 0, k * 64);
	}
}

void	wall(t_list *game, int i, int j)
{
	int	x;
	int	y;

	x = game->win_height - 1;
	y = game->win_width - 1;
	wall_render(game, x, y, 0);
	mb(game, i, j);
}
