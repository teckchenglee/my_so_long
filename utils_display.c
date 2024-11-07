/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:47:15 by tlee              #+#    #+#             */
/*   Updated: 2024/11/07 22:25:59 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_loadimages(t_data *data)
{
	int x;
	int y;

	x = data->width * TILE_SIZE;
	y = data->height * TILE_SIZE;
	data->img.exit = mlx_xpm_file_to_image(data->mlx,
		"./images/house.xpm",&x,&y);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
		"./images/wall.xpm",&x,&y);
	data->img.floor = mlx_xpm_file_to_image(data->mlx,
		"./images/path.xpm",&x,&y);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
		"./images/slime.xpm",&x,&y);
	data->img.gem = mlx_xpm_file_to_image(data->mlx,
		"./images/gem.xpm",&x,&y);
	if (data->img.exit == NULL || data->img.wall == NULL || data->img.floor
		== NULL ||data->img.player == NULL || data->img.gem == NULL)
	{
		ft_printf("Error: Invalid image!\n");
		free(data->img.exit),free(data->img.wall),free(data->img.floor);
		free(data->img.player), free(data->img.gem);
		exit(EXIT_FAILURE);
	}
}

// Helper function to display a tile at a specific position
static void display_tile(t_data *data, int x, int y, char tile)
{
	int image_x;
	int image_y;

	image_x = x * TILE_SIZE;
	image_y = y * TILE_SIZE;
	if (tile == '1')  // Wall
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			image_x, image_y);
	else if (tile == '0')  // Floor
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor,
			image_x, image_y);
	else if (tile == 'E')  // Exit
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit,
			image_x, image_y);
	else if (tile == 'C')  // Collectible
		mlx_put_image_to_window(data->mlx, data->win, data->img.gem,
			image_x, image_y);
	else if (tile == 'P')  // Player
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			image_x, image_y);
}

// Function to display everything (background, objects, player) in one pass
void ft_displayimage(t_data *data)
{
	int i;
	int j;

	i = 0;
	// Loop through the map once, rendering all elements
	while (i < data->height)  // Iterate over rows
	{
		j = 0;
		while (j < data->width)  // Iterate over columns
		{
			display_tile(data, j, i, data->map[i][j]);  // Display appropriate tile
			j++;
		}
		i++;
		
}
