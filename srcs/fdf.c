/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/14 16:10:38 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//#include "../minilibx_macos/mlx_ptr.h"

int	main(int argc, char **argv)
{
	fdf  **matrix;
	 
	matrix = NULL;
	matrix = alloc_and_height_fdf_map(argv[1]);
	init_matrix(matrix[0]);

	if (argc != 2)
		error_message(2);
	//print_matrix(&matrix);
    //create_fdf_map(argv[1], matrix);
	//read_n_create_map(argv[1], matrix);
    
	free(matrix);
	
		//mlx_pixel_put(mlx_ptr, mlx_win_ptr, i++, 700, 0x00FF0000);
	return (0);
}

// gcc *.c -lmlx -framework OpenGL -framework AppKit && ./a.out
	//int i = 100;
	// void	*mlx_ptr;
	// void	*mlx_win_ptr;
	// t_data	img;

	// mlx_ptr = mlx_init();
	// mlx_win_ptr = mlx_new_window(mlx_ptr, WIDTH, HIGH, "FDF FUCKERRRR");
	// img.img = mlx_new_image(mlx_ptr, WIDTH, HIGH);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 500, 700, 0x00FF0000);
	// mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, img.img, 0, 0);
	// mlx_loop(mlx_ptr);