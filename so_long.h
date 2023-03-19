/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:03:31 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/19 17:41:31 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "./utils/utils.h"
# include "./minilibx/mlx.h"
//#include <mlx.h>

typedef struct s_list {
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;

	char	**map;

	void	*floor;
	void	*walls;
	void	*exit;
}				t_list;

int		check_all(int argc, char **argv, t_list *game);
int		ft_error_print(char *str);
char	**map_r(char *file);
int		map_line_len(char **map, int len);
void	win_size(t_list *game);
void	img_add(t_list *game);
void	map_render(t_list *game);

#endif
