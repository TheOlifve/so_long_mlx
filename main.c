/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:47:25 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/19 17:41:33 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	game;


	ft_memset(&game, 0, sizeof(t_list));
	if(!(check_all(argc, argv, &game)))
		return (0);
	win_size(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.win_width * 64, game.win_height * 64, "SO LONG");
	img_add(&game);
	map_render(&game);
	mlx_loop(game.mlx);
	return (0);
}
