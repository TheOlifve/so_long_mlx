/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   girl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:24:03 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/23 11:24:08 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	girl_add(t_list *game)
{
	int	i;
	int	j;

	game->g_front2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/girl/g_front2.xpm", &i, &j);
	game->g_l2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/girl/g_l2.xpm", &i, &j);
	game->g_r2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/girl/g_r2.xpm", &i, &j);
	game->g_b2 = mlx_xpm_file_to_image(game->mlx,
			"sprites/girl/g_b2.xpm", &i, &j);
	game->h1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/heart/hb.xpm", &i, &j);
	game->hb = mlx_xpm_file_to_image(game->mlx,
			"sprites/heart/h1.xpm", &i, &j);
	game->door1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/door_o1.xpm", &i, &j);
	game->flw = mlx_xpm_file_to_image(game->mlx,
			"sprites/walls/flw.xpm", &i, &j);
}

void	girl_render(t_list *game)
{
	int	i;
	int	j;

	i = game->p_x;
	j = game->p_y;
	wall_add(game);
	girl_add(game);
	door(game);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->g_front2, j * 64, i * 64);
}
