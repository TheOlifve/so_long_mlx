/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:21:13 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/28 21:21:25 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sound(char *args[])
{
	int32_t		status;
	int32_t		pid;

	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], (char **)args);
		waitpid(pid, &status, 0);
	}
}