/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:19:53 by tlee              #+#    #+#             */
/*   Updated: 2024/11/06 22:05:22 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(void)
{
	ft_printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

static int mapheight(const char *map_name)
{
	int height;
	int fd;
	char *line;

	height = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_error();
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int mapwidth(const char *map_name)
{
	int width;
	int fd;
	char *line;

	width = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_error();
	line = get_next_line(fd);
	if (line != NULL)
	{
		width = ft_strlen(line) - 1;
		free(line);
	}
	close(fd);
	return (width);
}

int map_is_valid(t_data *data)
{
	t_count object;
	int i;
	int j;
	char c;

	object.exit_count = 0;
	object.player_count = 0;
	object.collectible_count = 0;
	i = 0;
	while (i < data->display_y)
	{
		j = 0;
		while (j < data->display_x)
		{
			c = data->map[i][j];
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c !='c')
			{
				ft_printf("Error: Invalid character '%c' in map.\n", c);
				return (0);
			}
			if (c == 'P')
				object.player_count++;
			if (c == 'E')
				object.exit_count++;
			if (c == 'C')
				object.collectible_count++;
			j++;
		}
		i++;
	}
	if (object.player_count != 1 || object.exit_count != 1 || object.collectible_count >= 1)
	{
		ft_printf("Error: Map must have only 1 player(P), 1 exit(E) and at least 1 collectible(C)\n");
		return (0);
	}
	return (1);
}

void ft_storemap(t_data *data)
{
	char *line;
	int fd;
	int i;

	i = 0;
	fd = open(data->map_name, O_RDONLY);
    if (fd == -1)
    {
		close(fd);
        free_data(data);
        ft_printf("Error: Failed to open map file.\n");
        exit(EXIT_FAILURE);
    }
	while (i < data->display_y)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free_data(data);
			close(fd);
			exit(EXIT_FAILURE);
		}
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
		{
			free(data->map[i]);
			free(line);
			break ;
		}
		free(line);
		i++;
	}
	close(fd);
}


void ft_readmap(t_data *data)
{
	data->display_y = mapheight(data->map_name);
	data->display_x = mapwidth(data->map_name);
	if (data->display_x == data->display_y)
	{
		ft_printf("Error: Invalid map format.\n");
		exit(EXIT_FAILURE);
	}
	data->width = data->display_x;
	data->height = data->display_y;
	ft_printf("Map (height:%d, width:%d):\n",data->display_y,data->display_x);
	data->map = ft_calloc(sizeof(char *), data->display_y + 1);
	if (data->map == NULL)
	{
		ft_printf("Error: Memory allocation for map failed.\n");
		exit(EXIT_FAILURE);
	}
	ft_storemap(data);
}
