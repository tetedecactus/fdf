/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/15 15:51:18 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	my_mlx_pixel_put(fdf *data, unsigned int x, unsigned int y, unsigned int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		data->addr[(x * 4) + (y * WIDTH_IMG * 4)] = color % 256; 
		data->addr[(x * 4) + (y * WIDTH_IMG * 4) + 1] = color / 256;
		data->addr[(x * 4) + (y * WIDTH_IMG * 4) + 2] = color / (256 * 256);
	}
}

float mod(float i)
{
	if (i < 0)
		i = -i;
	return(i);
}

void isometric(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->rotation_cos);
	*y = (*x + *y) * sin(data->rotation_sin) - z;
}

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = (data->matrix[(int)y][(int)x].z) * (data->projection);
	z1 = (data->matrix[(int)y1][(int)x1].z) * (data->projection);
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z || z1) ? RED : WHITE;
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = fmax(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		// (z || z1) ? my_mlx_pixel_put(data, x, y, RED) : my_mlx_pixel_put(data, x, y, WHITE);;
		my_mlx_pixel_put(data, x, y, data->color);
		// my_mlx_pixel_put(data, x, y, WHITE);
		x += x_step;
		y += y_step;
	}
}

void  clear_image(char *addr)
{
	int count = 0;
	while (count < (WIDTH_IMG * HEIGHT_IMG * 4))
		addr[count++] = 0;
}

void draw(fdf *data)
{
	int x;
	int y;
	
	y = 0;
	clear_image(data->addr);
	while ( y < data->map_height)
	{
		x = 0;
		while (x < data->map_width[y])
		{
			if (x < *data->map_width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->map_height - 1 /*&& (data->map_width[y] >= x && y <= data->map_height)*/)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void check_zoom(fdf *data)
{
	if (data->map_height > 200 &&  *data->map_width > 200)
		data->zoom = 2;
	else if (data->map_height >= 200 &&  *data->map_width >= 200)
		data->zoom = 5;
	else if (data->map_height >= 100)
		data->zoom = 7;
	else if (data->map_height > 50 &&  *data->map_width > 50)
		data->zoom = 8;
	else if (data->map_height == 50 &&  *data->map_width == 50)
		data->zoom = 12;
	else
		data->zoom = 20;
}

void draw_matrix(fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	init_data(data);
	data->img = mlx_new_image(data->mlx_ptr, WIDTH_IMG, HEIGHT_IMG);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	check_zoom(data);
	draw(data);
	mlx_key_hook(data->win_ptr, check_key, data);
	mlx_loop(data->mlx_ptr);
	free(data);
} 