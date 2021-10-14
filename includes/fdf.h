/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/14 16:01:16 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define WIDTH 1920
# define HIGH 1080

typedef struct	fdf 
{
	/*
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void 	*mlx_ptr;
	void 	*mlw_win_ptr;
*/
	float  	x;
	float 	y;
	float 	z;
	float 	color;
	float 	row;
	float 	col;		
	float	height;
	float 	width;
}				fdf;

// MiniLibX function
//void	my_mlx_pixel_put(fdf *data, int x, int y, int color);

// Read fucntion
void 	read_n_create_map(char *file_name, fdf **matrix);
void 	print_matrix(fdf **matrix);
fdf     **alloc_and_height_fdf_map(char *file_name);
void    init_matrix(fdf *parameters);
//void 	print_matrix(fdf **matrix);
fdf 	**create_fdf_map(char *file_name, fdf **matrix);


#endif