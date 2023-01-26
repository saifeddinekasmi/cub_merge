/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:18:49 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/26 02:01:45 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include "parsing/cub3d.h"
#include <math.h>


#define CUBE 10
#define VIEW  100
#define FEILD (60 * (M_PI / 180))
#define UP  13
#define DOWN 1
#define RIGHT 2
#define LEFT 0
#define WINDOW_W 1920
#define WINDOW_H 1080
int key_ringring;
typedef struct s_player
{
    double x;
    double y; 
    double ang;
    double speed;
    double turn_direction;
    double walk_direction;
    double rotation_speed;
    double view;
  
    
}t_player;

typedef struct s_ddavar
{
    double x1; // the x pos of the ray
    double y1;
    double xx1;
    double yy1;
    double xinc;
    double yinc;
    double steps;
    double  new_angle;
    double dx;
    double dy;
 
    //intersection

    double xsteps;
    double ysteps;
    double xinter;
    double yinter;
    int is_down; 
    int is_up;// is facing dow
    int is_right;
    int is_left;
    //
    double wallhitx;
    double wallhity;
    double distance;
    int h_found_wall;


    double xsteps1;
    double ysteps1;
    double xinter1;
    double yinter1;

    double next_x_inter;
    double next_y_inter;

    double next_x_inter1;
    double next_y_inter1;

    double wallhitx1;
    double wallhity1;
    double distance1;
    int v_found_wall;
    
    double num_rays;
    double distance_hor_wall;
    double distance_ver_wall;

} t_ddavar;


typedef struct s_three //struct dial 3d
{
    double d_player_pro; //distance player projection li dwa 3liha pikuma
    double wall_projection; //wall projection li dwa 3liha pikuma
    double ray_distance; //distamce bin ray w player
} t_three;


typedef struct s_ray
{
    double x;
    double y;
    double angle;
    int left;
    int right;
    int up;
    int down;
    double distance;
    
} t_ray;

typedef struct s_cub
{
    void *mlx;
    void *mlx_win;
    void	*img;
    void    *img1;
    char    *addr1;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


    int		bits_per_pixel1;
	int		line_length1;
	int		endian1;
    
    double map_w;
    double map_h;
    t_player player;
    char **walls;

    t_ddavar var_d;

    //for 3d
    t_three three;

    t_ray *ray;
    //for the minimap
    int map_i;
    int map_j;
    int map_x;
    int map_y;
    int black;
    int yellow;
    int red;
    int purple;
} t_all;

void init(t_all *cub);
void init_suite(t_all *cub);
int der(t_all *cub);
void	ft_error(char *str);
void launch_mlx(t_all *cub);
void draw_minimap(t_all *cub);
void	my_mlx_pixel_put(t_all *cub, int x, int y, int color);
void get_player_coord(t_all *cub);
int	mouvements(int key, t_all *cub);
void dda(t_all *cub);
void set_direction(t_all *cub);
int	exit_program(t_all *cub);
void event_left_right(t_all *cub, int key);
int check_walls2(t_all *cub, int flag);
int check_walls1(t_all *cub, int flag);
void	my_mlx_pixel_put2(t_all *cub, int x, int y, int color);
void init2(t_all *cub);
void make_rays(t_all *cub);

void draw_grid(t_all *cub, int grid, int fill);
void what_direction(t_all *cub);
void fix_angle(t_all *cub);
void is_down(t_all *cub);
void is_up(t_all *cub);
void is_left(t_all *cub);
void what_direction1(t_all *cub);
void is_right(t_all *cub);
void is_left(t_all *cub);
void is_up2(t_all *cub);
void is_left2(t_all *cub);
void normalize_player(t_all *cub);
void normalize_rayangle(t_all *cub);
void reset_directions(t_all *cub);
void decide_casting(t_all *cub);
void vertical_inter(t_all *cub);
void normalize_and_direction(t_all *cub);
void end_decide_casting(t_all *cub);
void begining_horizontal(t_all *cub);
void begining_vertical(t_all *cub);
void find_short_distance(t_all *cub);
void init_suite1(t_all *cub);
void init_suite0(t_all *cub);
int find_wall(int x, int y, t_all *cub);
void reset_variables(t_all *cub);
void generate_3d(t_all *cub);
void dda2(t_all *cub);
void put_big_player_circle(t_all *cub);
void horizontal_inter(t_all *cub);
void set_tab(t_ray *tab, t_all *cub);
void	my_mlx_pixel_put3(t_all *cub, int x, int y, int color);
void	*ft_calloc(size_t num, size_t size);
void	ft_bzero(void *str, size_t n);

#endif