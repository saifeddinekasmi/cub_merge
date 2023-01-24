/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:53:36 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/15 11:51:01 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int	exit_program(t_all *cub)
{
	int	index;

	index = 0;
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	while (index < cub->map_h / CUBE)
	{
		free(cub->walls[index]);
		index++;
	}
	free(cub->walls);
	exit(0);
}
