/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:53:36 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/22 13:37:15 by oufisaou         ###   ########.fr       */
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

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
