/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:47:25 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/22 16:52:31 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int	key, t_list *game)
{
	(void)game;
	(void)key;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	game;
	const char	*audio[] = {AUDIO, "./sprites/girl/hearteater.wav", NULL};

	ft_memset(&game, 0, sizeof(t_list));
	if(!(check_all(argc, argv, &game)))
		return (0);
	sound((char **)audio);
	game.coins += 1;
	game.d_img = 1;
	win_size(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.win_width * 64, game.win_height * 64, "Hearteater");
	wall(&game, -1, 0);
	girl_render(&game);
	draw_text(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx_win, 17, 1L << 0, ft_exit, &game);
	mlx_loop_hook(game.mlx, anim, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
