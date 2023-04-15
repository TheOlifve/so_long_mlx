/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:49:46 by hrahovha          #+#    #+#             */
/*   Updated: 2023/04/01 12:49:51 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_exit(t_list *game, int y, int x)
{
    if (game->map[y][x] == 'E')
        return (0);
    if (x >= game->win_height || y >= game->win_width || y < 0 || x < 0
        || game->map[y][x] == '1' || game->map[y][x] == 'N')
        return (1);
    else if (game->map[y][x] == 'E')
        return (0);
    game->map[y][x] = '1';
    if (fill_exit(game,y - 1, x) == 0)
        return (0);
    if (fill_exit(game,y + 1, x) == 0)
        return (0);
    if (fill_exit(game,y, x - 1) == 0)
        return (0);
    if (fill_exit(game,y, x + 1) == 0)
        return (0);
    return (1);
}

int fill_coin(t_list *game, int y, int x, int *coin)
{
    if (x >= game->win_height || y >= game->win_width || y < 0 || x < 0
        || game->map[y][x] == '1' || game->map[y][x] == 'N')
        return (1);
    if (game->map[y][x] == 'C')
        *coin -= 1;
    game->map[y][x] = '1';
    if (*coin == 0)
        return (0);
    if (fill_coin(game,y - 1, x, coin) == 0)
        return (0);
    if (fill_coin(game,y + 1, x, coin) == 0)
        return (0);
    if (fill_coin(game,y, x - 1, coin) == 0)    
        return (0);
    if (fill_coin(game,y, x + 1, coin) == 0)
        return (0);
    return (1);
}

int logic(t_list *game, int y, int x)
{
    int coin;

    coin = game->coins;
    while (game->map[++y])
    {
        x = -1;
        while (game->map[y][++x])
        {
            if (game->map[y][x] == 'P')
            {
                if (fill_exit(game,y, x) == 0 && fill_coin(game, y, x, &coin) == 0)
                    return (0);
            }
        }
    }
    return (1);
}