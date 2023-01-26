/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <oufisaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:26:29 by oufisaou          #+#    #+#             */
/*   Updated: 2023/01/25 16:02:38 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void what_direction(t_all *cub)
{
    if(cub->var_d.new_angle >= 0 && cub->var_d.new_angle <= M_PI)
        cub->var_d.is_down = 1;
    else if (cub->var_d.new_angle > M_PI && cub->var_d.new_angle < 2 * M_PI)
        cub->var_d.is_up = 1;
    if (cub->var_d.new_angle <= M_PI / 2.0 || cub->var_d.new_angle > 3.0 * M_PI / 2.0)
        cub->var_d.is_right = 1;
    else if (cub->var_d.new_angle >= M_PI / 2 && cub->var_d.new_angle < 3 * M_PI / 2)
        cub->var_d.is_left = 1;
        
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
}

void is_left(t_all *cub)
{
    if(cub->var_d.is_left == 1 &&  cub->var_d.xsteps > 0)
        cub->var_d.xsteps *= -1;
    if (cub->var_d.is_right == 1 && cub->var_d.xsteps < 0)
        cub->var_d.xsteps *= -1;

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

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if(p == 0)
		return (p);
	ft_bzero(p, num * size);
	return (p);

}
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, '\0', n);
}
