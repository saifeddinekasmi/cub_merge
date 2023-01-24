/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:26:29 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/24 00:03:27 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void what_direction(t_all *cub)
{
    if(cub->var_d.new_angle >= 0 && cub->var_d.new_angle <= M_PI)
    {
        cub->var_d.is_down = 1;
        // printf("down\n");
    }
    else if (cub->var_d.new_angle > M_PI && cub->var_d.new_angle < 2 * M_PI)
    {
        cub->var_d.is_up = 1;
                // printf("up\n");
    }
    if (cub->var_d.new_angle <= M_PI / 2.0 || cub->var_d.new_angle > 3.0 * M_PI / 2.0)
    {
        cub->var_d.is_right = 1;
        // printf("right\n");
    }
    else if (cub->var_d.new_angle >= M_PI / 2 && cub->var_d.new_angle < 3 * M_PI / 2)
    {
        cub->var_d.is_left = 1;
        // printf("left\n");
    }
        
}

void is_down(t_all *cub)
{
    if(cub->var_d.is_down == 1)
        cub->var_d.yinter += CUBE;
    else
        cub->var_d.yinter += 0;
}

void is_right(t_all *cub)
{
    if(cub->var_d.is_right == 1)
        cub->var_d.xinter1 += CUBE;
    else
        cub->var_d.xinter1 += 0;
}

void is_up(t_all *cub)
{
    if(cub->var_d.is_up == 1 && cub->var_d.ysteps > 0)
        cub->var_d.ysteps *= -1;
    if(cub->var_d.is_down == 1 && cub->var_d.ysteps < 0)
        cub->var_d.ysteps *= -1;
    // else
    //     cub->var_d.ysteps *= 1;
}

void is_left(t_all *cub)
{
    if(cub->var_d.is_left == 1 &&  cub->var_d.xsteps > 0)
        cub->var_d.xsteps *= -1;
    if (cub->var_d.is_right == 1 && cub->var_d.xsteps < 0)
        cub->var_d.xsteps *= -1;
    // else
    //     cub->var_d.xsteps *= 1;
}

void is_left2(t_all *cub)
{
    if(cub->var_d.is_left == 1 &&  cub->var_d.xsteps1 > 0)
        cub->var_d.xsteps1 *= -1;
    if (cub->var_d.is_right == 1 && cub->var_d.xsteps1 < 0)
        cub->var_d.xsteps1 *= -1;
}

void is_up2(t_all *cub)
{
    if((cub->var_d.is_up == 1 && cub->var_d.ysteps1 > 0) || (cub->var_d.is_down == 1 && cub->var_d.ysteps1 < 0))
        cub->var_d.ysteps1 *= -1;
}