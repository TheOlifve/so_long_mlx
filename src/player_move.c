/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:35:30 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/23 15:35:34 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_text(t_list *game)
{
	char	*str;
	int		i;
	int		j;

	i = game->door_x;
	j = game->door_y;
	str = ft_itoa(game->score);
	ft_printf("%s\n", str);
	empty(game, 0, 0);
	if (game->coins == 0)
	{
		empty(game, i, j);
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->door1, j * 64, i * 64);
	}
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, game->wall_ul, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win,
		32, 32, 0x00FF0000, str);
	free(str);
}

int	key_press(int key, t_list *game)
{
	int	i;
	int	j;

	i = game->p_x;
	j = game->p_y;
	if (key == 13 || key == 126)
		move_up(game, i, j);
	else if (key == 1 || key == 125)
		move_down(game, i, j);
	else if (key == 0 || key == 123)
		move_left(game, i, j);
	else if (key == 2 || key == 124)
		move_right(game, i, j);
	else if (key == 53)
		ft_exit(game);
	draw_text(game);
	int k = -1;
	while (game->map[++k])
		printf ("%s\n", game->map[k]);
	printf ("\n\n");
	return (0);
}
