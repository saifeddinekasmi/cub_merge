/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:14:40 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/26 02:06:46 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void begining_horizontal(t_all *cub)
{
    what_direction(cub);
    cub->var_d.yinter = floor(cub->player.y / CUBE) * (double)CUBE;
    is_down(cub);
    cub->var_d.xinter = cub->player.x + ((cub->var_d.yinter - cub->player.y) / tan(cub->var_d.new_angle));
    cub->var_d.ysteps = CUBE;
    is_up(cub);
    cub->var_d.xsteps = CUBE / tan(cub->var_d.new_angle);
    is_left(cub);
    cub->var_d.next_x_inter = cub->var_d.xinter;
    cub->var_d.next_y_inter = cub->var_d.yinter;
}



void end_decide_casting(t_all *cub)
{
    cub->var_d.xx1 = cub->player.x;
    cub->var_d.yy1 =  cub->player.y;

    cub->var_d.dx = cub->var_d.x1 - cub->var_d.xx1;
    cub->var_d.dy = cub->var_d.y1 - cub->var_d.yy1;
    if(fabs(cub->var_d.dx) > fabs(cub->var_d.dy))
        cub->var_d.steps = fabs(cub->var_d.dx);
    else
        cub->var_d.steps = fabs(cub->var_d.dy);
    // dda2(cub);
}

void begining_vertical(t_all *cub)
{
    what_direction(cub);
    cub->var_d.xinter1 = floor(cub->player.x / CUBE) * (double)CUBE;
    is_right(cub);
    cub->var_d.yinter1 = cub->player.y + ((cub->var_d.xinter1 - cub->player.x) * tan(cub->var_d.new_angle));
    cub->var_d.xsteps1 = CUBE;
    is_left2(cub);
    cub->var_d.ysteps1 = CUBE * tan(cub->var_d.new_angle);
    is_up2(cub); 
    cub->var_d.next_x_inter1= cub->var_d.xinter1;
    cub->var_d.next_y_inter1 = cub->var_d.yinter1;
}