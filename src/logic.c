/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:37:20 by rugrigor          #+#    #+#             */
/*   Updated: 2023/03/27 19:37:24 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int fill_exit(t_list *game, int x, int y)
{
    if (game->map[x][y] == 'E')
        return (0);
    if (x >= game->win_width || y >= game->win_height || y < 0 || x < 0
        || game->map[x][y] == '1' || game->map[x][y] == 'N')
        return (1);
    else if (game->map[x][y] == 'E')
        return (0);
    game->map[x][y] = '1';
    if (fill_exit(game, x - 1, y) == 0)
        return (0);
    if (fill_exit(game, x + 1, y) == 0)
        return (0);
    if (fill_exit(game, x, y - 1) == 0)
        return (0);
    if (fill_exit(game, x, y + 1) == 0)
        return (0);
    return (1);
}

int fill_coin(t_list *game, int x, int y, int *coin)
{
    if (x >= game->win_width || y >= game->win_height || y < 0 || x < 0
        || game->map[x][y] == '1' || game->map[x][y] == 'N')
        return (1);
    if (game->map[x][y] == 'C')
        *coin -= 1;
    game->map[x][y] = '1';
    if (*coin == 0)
        return (0);
    if (fill_coin(game, x - 1, y, coin) == 0)
        return (0);
    if (fill_coin(game, x + 1, y, coin) == 0)
        return (0);
    if (fill_coin(game, x, y - 1, coin) == 0)
        return (0);
    if (fill_coin(game, x, y + 1, coin) == 0)
        return (0);
    return (1);
}

int logic(t_list *game)
{
    int coin;
    int x;
    int y;

    x = -1;
    coin = game->coins;
    while (game->map[++x])
    {
        y = -1;
        while (game->map[x][++y])
        {
            if (game->map[x][y] == 'P')
            {
                if (fill_exit(game, x, y) == 0 && fill_coin(game, x, y, &coin) == 0)
                    return (0);
            }
        }
    }
    return (1);
}
