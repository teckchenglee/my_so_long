/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:47:15 by tlee              #+#    #+#             */
/*   Updated: 2024/11/06 21:47:51 by tlee             ###   ########.fr       */
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

void	display_bg(t_data *data, int i, int j)
{
	int	x;
	int	y;

	while (data->map[i])
	{
		y = i * TILE_SIZE;
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			x = j * TILE_SIZE;
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.wall, x, y);
			}
			else if (data->map[i][j] == '0')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.floor, x, y);
			}
			j++;
		}
		i++;
	}
}
void	display_obj(t_data *data, int i, int j)
{
	int	x;
	int	y;

	while (data->map[i])
	{
		y = i * TILE_SIZE;
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			x = j * TILE_SIZE;
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.exit, x, y);
			}
			else if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.gem, x, y);
			}
			j++;
		}
		i++;
	}
}

void	display_player(t_data *data, int i, int j)
{
	int	x;
	int	y;

	while (data->map[i])
	{
		y = i * TILE_SIZE;
		j = 0;
		while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
		{
			x = j * TILE_SIZE;
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.player, x, y);
			}
			j++;
		}
		i++;
	}
}

void ft_displayimage(t_data *data)
{
	display_bg(data,0,0);
	display_obj(data,0,0);
	display_player(data,0,0);
	mlx_string_put(data->mlx, data->win, 24, data->height, 0x00000000,"42 Singapore Teck Cheng");
}