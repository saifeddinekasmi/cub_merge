/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:11 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/25 13:52:52 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put2(t_all *cub, int x, int y, int color)
{
	char	*dst;
    
    if ((x >= 0 && x < cub->map_w) && (y >= 0 && y < cub->map_h))
    {
        dst = cub->addr + ((y * cub->line_length) + (x * (cub->bits_per_pixel / 8)));
        *(unsigned int*)dst = color;
    }
}


void	my_mlx_pixel_put3(t_all *cub, int x, int y, int color)
{
	char	*dst;
    
    if ((x >= 0 && x < WINDOW_W) && (y >= 0 && y < WINDOW_H))
    {
        dst = cub->addr1 + ((y * cub->line_length1) + (x * (cub->bits_per_pixel1 / 8)));
        *(unsigned int*)dst = color;
    }
}

void draw_grid(t_all *cub, int grid, int fill)
{
        cub->map_x = cub->map_j * CUBE;

        while (cub->map_x < (cub->map_j * CUBE) + CUBE)
        {
            if (cub->map_y % CUBE == 0 || cub->map_x % CUBE == 0) //put black line
                my_mlx_pixel_put2(cub, cub->map_x, cub->map_y, grid);
            else
                my_mlx_pixel_put2(cub, cub->map_x, cub->map_y, fill);
            cub->map_x++;
        }
        cub->map_y++;
    
}

void draw_minimap(t_all *cub)
{
	while(cub->map_i < cub->map_h / CUBE) // cub->map_i will itterate on 7 height
    {
        cub->map_j = 0;
        while(cub->map_j < cub->map_w / CUBE) // cub->map_j will itterate on 10 width
        {
            cub->map_y = cub->map_i * CUBE; 
            if (cub->walls[cub->map_i][cub->map_j] == '1')
            {
                while(cub->map_y < (cub->map_i * CUBE) + CUBE) //while the height is less than the end of the square  
                     draw_grid(cub, cub->black, cub->yellow);
            }
            else if(cub->walls[cub->map_i][cub->map_j] == '0')
            {
                while(cub->map_y < (cub->map_i * CUBE) + CUBE) 
                     draw_grid(cub, cub->black, cub->purple);
            }
            else
            {
                while(cub->map_y < (cub->map_i * CUBE) + CUBE) 
                     draw_grid(cub, cub->black, cub->red);
            }
            cub->map_j++;
        }
        cub->map_i++;
    }
    reset_variables(cub);
    return ;
}


void reset_variables(t_all *cub)
{
    cub->map_i = 0;
    cub->map_j = 0;  //to prevent duplication
    cub->map_x = 0;
    cub->map_y = 0;
}
void get_player_coord(t_all *cub)
{
    int i;
    int j;

    i = 0;
    while(i < cub->map_h / CUBE)
    {
        j = 0;
        while(j < cub->map_w / CUBE)
        {
            if (cub->walls[i][j] == 'N' || cub->walls[i][j] == 'S' || cub->walls[i][j] == 'W' || cub->walls[i][j] == 'E') //it can be other directions
            {
                    cub->player.y = (i * CUBE) + CUBE / 2;
                    cub->player.x = (j * CUBE) + CUBE / 2;
            }
            j++;
        }
        i++;
    } 
}

void put_big_player_circle(t_all *cub)
{
    double h;
    double angle;
    double x_big;
    double y_big;

    my_mlx_pixel_put2(cub, cub->player.x, cub->player.y, 0x00FFFFFF);
    //x = cos(o) * h + xs
    //y = sin(o) * h + ys
    h = 1;
    while(h < 5) // this h increments
    {
        angle = 0;
        while(angle < 360)
        {
            x_big = cos(angle) * h + cub->player.x;
            y_big = sin(angle) * h + cub->player.y;
            my_mlx_pixel_put2(cub, x_big, y_big, 0x00FFFFFF);
            angle++;
        }
        h++;
    }
    return ;    
}


