/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:37 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/24 16:33:12 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include "header.h"

int main(int ac, char **av)
{
    t_all cub;
    t_map	map;
    t_texture	t;

	t.ea = NULL;
	t.no = NULL;
	t.so = NULL;
	t.we = NULL;
	map.t = &t;
    if (ac != 2)
	{
		ft_putstr_fd("Error Args !!!\n", 2);
		exit(1);
	}
	if (ft_check_file_map(av) == 1)
	{
		ft_putstr_fd("\033[0;31mextention of map must finished -> .cub !!\n",2);
		exit(1);
	}
	ft_read_map(&map, av);
	// map.map_height = ft_get_len_ofmap(map.all_map2d);
	map.map_width = get_len(map.all_map2d);
	ft_check_line_before_map(map.all_map2d, &map);
	ft_check_map_len(&map);
	if (ft_export_only_map2d(&map) == 1)
	{
		printf("error");
		exit(1);
	}
	map.width_only_map = get_width(map.only_map);
	map.height_only_map = get_height(map.only_map);
	retrun_map_2d_withspace(&map);
	if (ft_check_content(&map) || ft_check_all_map(map.only_map) ||
		ft_check_horizontal(&map) || ft_check_vertical(&map))
	{
		printf("error walls content\n");
		exit(EXIT_FAILURE);
	}
    cub.walls = map.only_map;
    cub.map_w = map.width_only_map * CUBE;
    cub.map_h = map.height_only_map * CUBE;
    init(&cub);
    launch_mlx(&cub);
	
}