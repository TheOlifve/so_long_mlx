/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:51:46 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/26 11:52:00 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int    d_anim(t_list *game, int k)
{
    if (k <= 1000)
        game->door = game->door7;
    else if (k == 2000)
        game->door = game->door2;
    else if (k == 3000)
        game->door = game->door3;
    else if (k == 4000)
        game->door = game->door4;
    else if (k == 5000)
        game->door = game->door5;
    if (k == 6000)
    {
        game->door = game->door6;
        return (1);
    }
    return (k);
}

int anim(t_list *game)
{
    static int k;
    int i;
    int j;
    int x;
    int y;

    x = -1;
    y = -1;
    i = game->door_x;
    j = game->door_y;
    while (game->map[++y])
    {
        x = -1;
        while(game->map[y][++x])
        {
            k = d_anim(game, k);
            if(game->coins == 0)
                game->door = game->door1;
            mlx_put_image_to_window(game->mlx,
            game->mlx_win, game->door, j * 64, i * 64);
            k++;
        }
    }
    return (0);
}
