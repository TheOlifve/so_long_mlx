/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:37:33 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/25 12:37:45 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loot_dcoin_r(t_list *game, int i, int j)
{
	empty(game, i, j - 1);
	game->map[i][j] = '7';
	game->coins -= 1;
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->hb, j * 64, i * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->hb, (j - 1) * 64, i * 64);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->g_r2, j * 64, i * 64);
}

void	loot_coin_r(t_list *game, int i, int j)
{
	game->p_y = j;
	if (game->map[i][j - 1] == '7' && game->map[i][j] == 'C')
		loot_dcoin_r(game, i, j);
	else if (game->map[i][j] == 'C')
	{
		game->map[i][j] = '7';
		game->coins -= 1;
		empty(game, i, j - 1);
		empty(game, i, j);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->hb, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->g_r2, j * 64, i * 64);
	}
	else if (game->map[i][j - 1] == '7')
	{
		j -= 1;
		empty(game, i, j);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->hb, j * 64, i * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->g_r2, (j + 1) * 64, i * 64);
	}
}

void	move_right(t_list *game, int i, int j)
{
	game->score += 1;
	j += 1;
	if (game->map[i][j] == 'N' || (game->map[i][j] == 'E'
		&& game->coins == 0))
		ft_exit(game);
	else if (game->map[i][j] != '1' && (game->map[i][j] == 'C'
		|| game->map[i][j - 1] == '7'))
		loot_coin_r(game, i, j);
	else if (game->map[i][j] != '1')
	{
		game->p_y = j;
		empty(game, i, j - 1);
		if (game->map[i][j - 1] == 'E' && game->coins > 0)
			mlx_put_image_to_window(game->mlx,
				game->mlx_win, game->door, (j - 1) * 64, i * 64);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->g_r2, j * 64, i * 64);
	}
}
