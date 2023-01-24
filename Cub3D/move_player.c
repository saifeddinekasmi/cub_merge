/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:27:59 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/17 16:54:14 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void event_left_right(t_all *cub, int key)
{
    double angle;

	if (key == RIGHT) 
	{
        if(!check_walls1(cub, 1))
        {
            angle = cub->player.ang - (90 * (M_PI / 180));
            cub->player.x -= (cos(angle) * cub->player.speed); //in case of North : x = x - (cos((3PI / 2- pI/2) * 3) = 330 - 4 = 226 
            cub->player.y -= (sin(angle) * cub->player.speed); // 0 
        }
	}
	if (key == LEFT) 
	{
        if(!check_walls1(cub, 0))
        {
            angle = cub->player.ang - (90 * (M_PI / 180));
            cub->player.x += (cos(angle) * cub->player.speed);
            cub->player.y += (sin(angle) * cub->player.speed); //y is fix
        }
    }
}


void event_up_down(t_all *cub, int key)
{
	if (key == UP)
    {
        if(!check_walls2(cub, 1))
        {
            cub->player.x += cos(cub->player.ang) * cub->player.speed;//0
            cub->player.y += sin(cub->player.ang) *  cub->player.speed; // y - (cos(ang) * speed)
        }
        
    }
	if(key == DOWN)
    {
        if(!check_walls2(cub, 0))
        {
            cub->player.x += cos(cub->player.ang) * (cub->player.speed * -1);//0
            cub->player.y += sin(cub->player.ang) * (cub->player.speed * -1);
        }
    }
}

void rotate_player(int key, t_all *cub)
{
    if(key == 35)
    {
        cub->player.ang -= cub->player.rotation_speed;
    }
    else if (key == 31)
    {
        cub->player.ang += cub->player.rotation_speed;
    }
    // normalize_player(cub);
}

int	mouvements(int key, t_all *cub)
{
    // printf("x: %f | y : %f\n", cub->player.x , cub->player.y);
	if (key == RIGHT || key == LEFT)
		event_left_right(cub, key);
	else if (key == UP || key == DOWN)
		event_up_down(cub, key);
    else if (key == 53)
		exit_program(cub);
    else
        rotate_player(key, cub);
    // normalize_player(cub);
    draw_minimap(cub);
    put_big_player_circle(cub);
    make_rays(cub);
    dda(cub);
    mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img, 0, 0);
    // normalize_player(cub);
    return (1);
}
