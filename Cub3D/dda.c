/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:39:22 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/26 00:20:32 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

/*
    this function calclates the position of the end of the ray,
    This is the function for the red line
*/

/*
    this fuction draw a ray in finction of the parameters:
    @var_d.xinc : the x increment value
    @
*/

void dda(t_all *cub)
{
    //why pi / 2 looks down : becaue they go in the way of the horloge in game development
    //ihdatiyat dial no9ta
    
    int i;

    i = 0;
    cub->var_d.x1 = cub->player.x + (cos(cub->player.ang) * VIEW);
    cub->var_d.y1 = cub->player.y + (sin(cub->player.ang) * VIEW);

    cub->var_d.xx1  = cub->player.x;
    cub->var_d.yy1 = cub->player.y;

    if(fabs(cub->var_d.x1 - cub->player.x) > fabs(cub->var_d.y1 -  cub->player.y))
        cub->var_d.steps = fabs(cub->var_d.x1 - cub->player.x);
    else
        cub->var_d.steps = fabs(cub->var_d.y1 - cub->player.y);

    cub->var_d.xinc = (cub->var_d.x1 - cub->player.x) / cub->var_d.steps;
    cub->var_d.yinc = (cub->var_d.y1 - cub->player.y) / cub->var_d.steps;

    while(i < cub->var_d.steps)
    {
        my_mlx_pixel_put2(cub, cub->var_d.xx1 , cub->var_d.yy1, 0x00FF0000);
        cub->var_d.xx1 = cub->var_d.xx1 + cub->var_d.xinc;
        cub->var_d.yy1 = cub->var_d.yy1 + cub->var_d.yinc;
        i++;
    }
}
void dda2(t_all *cub)
{
    static int how_many;
    //why pi / 2 looks down : becaue they go in the way of the horloge in game development
    //ihdatiyat dial no9ta
    int i;
  

    i = 0;
    cub->var_d.xinc = (cub->var_d.dx) / cub->var_d.steps;
    cub->var_d.yinc = (cub->var_d.dy) / cub->var_d.steps;
    // printf("xx = %f\t%f\n", cub->var_d.xinc , cub->var_d.yinc);
    while(i <= cub->var_d.steps)
    {
        my_mlx_pixel_put2(cub, round(cub->var_d.xx1) , round(cub->var_d.yy1), 0x0000CC00);
        cub->var_d.xx1 += cub->var_d.xinc;
        cub->var_d.yy1 += cub->var_d.yinc;
        i++;
    }
    if (i != 0)
    {
        ++how_many;
        // printf("omoormedobuta\n");

    }
    // printf("how = %d\n", how_many);
}

void normalize_player(t_all *cub)
{
    cub->player.ang = fmod(cub->var_d.new_angle ,(2 * M_PI));
    if (cub->player.ang < 0) {
        cub->player.ang = (2 * M_PI) + cub->player.ang;
    }
}

void normalize_rayangle(t_all *cub)
{ 
    // cub->var_d.new_angle = fmod(cub->var_d.new_angle , 2 * M_PI); //to reset  to 0
    // if (cub->var_d.new_angle  < 0)
    //     cub->var_d.new_angle += 2 * M_PI;

    cub->var_d.new_angle = fmod(cub->var_d.new_angle ,(2 * M_PI));
    if (cub->var_d.new_angle < 0) {
        cub->var_d.new_angle = (2 * M_PI) + cub->var_d.new_angle;
    }
}

/*
    This function  Takes the player angle and takes 30 degree from it and start creating each 
    ray by increasing the angle with a 60 / NUM RAY
*/
void make_rays(t_all *cub)
{
    int  j;
    double width;
    double angle;

    j = 0;
    // normalize_player(cub);
    width = cub->map_w;
    angle = cub->player.ang;
    cub->var_d.num_rays = width;
    cub->var_d.new_angle = angle - (FEILD / 2);
    normalize_rayangle(cub);
    // printf("width: %lf\n", cub->map_w);
    while(j < cub->var_d.num_rays)  //NUMRAYS IS ACTUALYY MAP_W
    {
        // printf("-->%f\n", cub->var_d.new_angle);
        
            horizontal_inter(cub); 
            vertical_inter(cub);
            decide_casting(cub);
            reset_directions(cub);
            normalize_rayangle(cub);
            cub->var_d.new_angle += (FEILD / cub->var_d.num_rays);
            // printf("hahowa : %lf\n", );
            normalize_rayangle(cub);
        j++;
    }
    // printf("%d\n", j);
}

void reset_directions(t_all *cub)
{
    cub->var_d.is_down = 0;
    cub->var_d.is_right = 0;
    cub->var_d.is_up = 0;
    cub->var_d.is_left = 0;
    cub->var_d.x1 = 0;
    cub->var_d.y1 = 0;
    cub->var_d.wallhitx = 0;
    cub->var_d.wallhity = 0;
    cub->var_d.wallhitx1 = 0;
    cub->var_d.wallhity1 = 0;
    cub->var_d.h_found_wall = 0;
    cub->var_d.v_found_wall = 0;
}

void decide_casting(t_all *cub)
{
        double d1 = 0;
        double d2 = 0;

        // static int x = 0;
        // d1 = sqrt(((cub->var_d.wallhitx - cub->player.x) * (cub->var_d.wallhitx - cub->player.x))  + ((cub->var_d.wallhity - cub->player.y) * (cub->var_d.wallhity - cub->player.y)));
        // d2 = sqrt(((cub->var_d.wallhitx1 - cub->player.x) * (cub->var_d.wallhitx1 - cub->player.x))  + ((cub->var_d.wallhity1 - cub->player.y) * (cub->var_d.wallhity1 - cub->player.y)));
        d1 = hypot(cub->var_d.wallhitx - cub->player.x, cub->var_d.wallhity - cub->player.y);
        d2 = hypot(cub->var_d.wallhitx1 - cub->player.x, cub->var_d.wallhity1 - cub->player.y);
        // if (!d1 && !d2)
        // {
        //     printf("impossible\n");
        //     exit(1);
        // }
        // printf("hori %f vertical  %f\n", d1, d2);
        // printf("horizontal ta3 nam: %lf\t%lf\n", cub->var_d.wallhitx, cub->var_d.wallhity);
        // printf("vertical ta3 nam: %lf\t%lf\n", cub->var_d.wallhitx1, cub->var_d.wallhity1);
        if (cub->var_d.h_found_wall && cub->var_d.v_found_wall)
        {
            if(d1 <= d2)
            {
                cub->var_d.x1 = cub->var_d.wallhitx;
                cub->var_d.y1 = cub->var_d.wallhity;
            
            }
            else
            {
                cub->var_d.x1 = cub->var_d.wallhitx1;
                cub->var_d.y1 = cub->var_d.wallhity1;
            }
        }
        else if (cub->var_d.h_found_wall)
        {
                cub->var_d.x1 = cub->var_d.wallhitx;
                cub->var_d.y1 = cub->var_d.wallhity;
        }
        else if (cub->var_d.v_found_wall)
        {
                cub->var_d.x1 = cub->var_d.wallhitx1;
                cub->var_d.y1 = cub->var_d.wallhity1;
        }
        cub->var_d.xx1 = cub->player.x;
        cub->var_d.yy1 =  cub->player.y;

        cub->var_d.dx = cub->var_d.x1 - cub->var_d.xx1;
        cub->var_d.dy = cub->var_d.y1 - cub->var_d.yy1;
        if(fabs(cub->var_d.dx) > fabs(cub->var_d.dy))
            cub->var_d.steps = fabs(cub->var_d.dx);
        else
            cub->var_d.steps = fabs(cub->var_d.dy);

        // printf("%d\n", x++);
        // printf("x : %f\n y: %f\n", cub->var_d.x1, cub->var_d.y1);
        dda2(cub);
        
}

void horizontal_inter(t_all *cub)
{
    what_direction(cub);
    // printf(" up : %d\n  down:%d\n   left: %d\n right: %d\n", cub->var_d.is_up, cub->var_d.is_down, cub->var_d.is_left, cub->var_d.is_right);
    // printf("incrementation: %f\n new:%f\n", FEILD / 2, cub->var_d.new_angle);
    cub->var_d.yinter = floor(cub->player.y / CUBE) * (double)CUBE;
    is_down(cub);
    cub->var_d.xinter = cub->player.x + ((cub->var_d.yinter - cub->player.y) / tan(cub->var_d.new_angle));
    
    cub->var_d.ysteps = CUBE;
    is_up(cub);
    cub->var_d.xsteps = CUBE / tan(cub->var_d.new_angle);
    is_left(cub);

    cub->var_d.next_x_inter = cub->var_d.xinter;
    cub->var_d.next_y_inter = cub->var_d.yinter;

    // if(cub->var_d.is_up == 1)
    //     cub->var_d.next_y_inter -= 0.00000001;
        
    while(cub->var_d.next_x_inter >= 0 && cub->var_d.next_x_inter < cub->map_w \
    && cub->var_d.next_y_inter >= 0 && cub->var_d.next_y_inter < cub->map_h)
    {
        if (cub->var_d.is_up == 1)
        {
            if(cub->walls[(int)((cub->var_d.next_y_inter - 1) / CUBE)][(int)(cub->var_d.next_x_inter / CUBE)] == '1')
            {
                cub->var_d.h_found_wall = 1;
                cub->var_d.wallhitx = cub->var_d.next_x_inter;
                cub->var_d.wallhity = cub->var_d.next_y_inter;
                break ;
            }

        }
        if(cub->walls[(int)((cub->var_d.next_y_inter) / CUBE)][(int)(cub->var_d.next_x_inter / CUBE)] == '1')
        {
            cub->var_d.h_found_wall = 1;
            cub->var_d.wallhitx = cub->var_d.next_x_inter;
            cub->var_d.wallhity = cub->var_d.next_y_inter;
            break ;
        }  
            cub->var_d.next_x_inter += cub->var_d.xsteps;
            cub->var_d.next_y_inter += cub->var_d.ysteps;
    }
    // normalize_rayangle(cub);
    // normalize_player(cub);
    
}

void normalize_and_direction(t_all *cub)
{
    normalize_rayangle(cub);
    normalize_player(cub);

}

void vertical_inter(t_all *cub)
{
    // normalize_rayangle(cub);
    // if (cub->var_d.new_angle == M_PI / 2 || cub->var_d.new_angle == 3 * M_PI / 2)
    // {
    //     puts("hello");
    //     exit(0);
    // }
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

    // if(cub->var_d.is_left == 1)
    //    cub->var_d.next_x_inter1 -= 0.00000001;
    
    while(cub->var_d.next_x_inter1  >= 0 && cub->var_d.next_x_inter1  < cub->map_w \
    && cub->var_d.next_y_inter1 >= 0 && cub->var_d.next_y_inter1 < cub->map_h)
    {
        if (cub->var_d.is_left == 1)
        {
            if(cub->walls[(int)(cub->var_d.next_y_inter1 / CUBE)][(int)((cub->var_d.next_x_inter1 -1) / CUBE)] == '1')
            {
                // puts("here");
                cub->var_d.v_found_wall = 1;
                cub->var_d.wallhitx1 = cub->var_d.next_x_inter1;
                cub->var_d.wallhity1 = cub->var_d.next_y_inter1;
                break ;
            }

        }
        if(cub->walls[(int)(cub->var_d.next_y_inter1 / CUBE)][(int)(cub->var_d.next_x_inter1 / CUBE)] == '1')
        {
                cub->var_d.v_found_wall = 1;
                cub->var_d.wallhitx1 = cub->var_d.next_x_inter1;
                cub->var_d.wallhity1 = cub->var_d.next_y_inter1;
                break ;   
        }
            cub->var_d.next_x_inter1 += cub->var_d.xsteps1;
            cub->var_d.next_y_inter1  += cub->var_d.ysteps1;
    }
    // normalize_rayangle(cub);
    // normalize_player(cub);
}