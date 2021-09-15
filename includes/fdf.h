/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/15 16:00:53 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "../minilibx_macos/mlx.h"

#define WIDTH 1920
#define HIGH 1080

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// MiniLibX function
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif