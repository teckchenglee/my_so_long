/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:06:46 by tlee              #+#    #+#             */
/*   Updated: 2024/11/06 22:08:47 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\\n", keysym);
	return (0);
}


int	ft_count_len(int fd)
{
	int nl_counter;
	char buffer[1];
	int size;

	buffer[0] = '\0';
	size = 1;
	nl_counter = 0;
	while (size == 1)
	{
		size = read(fd, buffer ,1);
		if (buffer[0] != '\n')
			nl_counter++;
		else
			break ;
	}
	return (nl_counter);
}

int	ft_count_lines(int fd, int x, int img_w)
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| ((int)ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}

void	window_size(t_data *data, char **argv)
{ 
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)  
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE); 
	}
	data->size_x = (ft_count_len(fd) * 32); 
	data->size_y = (ft_count_lines(fd, data->size_x, 32) * 32);
}

int	endswith_ber(char *filename)
{
	if (strlen(filename) < 4)
		return (0);
	return (strcmp(filename + strlen(filename) - 4, ".ber") == 0);
}*/
void free_data(t_data *data)
{
	int	i;

	ft_printf("Freeing data:\n");
	if (data->map)
	{
		ft_printf("Freeing map...\n");
		i = 0;
		while(data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	if (data->map_name)
	{
		ft_printf("Freeing map name...\n");
		free(data->map_name);
		data->map_name = NULL;
	}
		
	if (data->win)
	{
		ft_printf("Destroying window...\n");
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		ft_printf("Cleaning up mlx...\n");
		free(data->mlx);
		data->mlx =NULL;
	}
	
	
}
void	ft_exit(t_data *data)
{
	mlx_loop_end(data->mlx);
	//free_images(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//free_double_pointer(vars->map);
	//free_map_copy(vars);
	exit(0);
}

int ft_esckey(t_data *data)
{
	ft_printf("Escape\n");
	ft_exit(data);
	exit(EXIT_SUCCESS);
}
void	move_up(t_data *vars)
{
	if (vars->map[vars->player_x - 1][vars->player_y] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_y -= TILE_SIZE;
		vars->player_x -= 1;
		++vars->move_count;
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	move_down(t_data *vars)
{
	if (vars->map[vars->player_x + 1][vars->player_y] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_y += TILE_SIZE;
		vars->player_x += 1;
		++vars->move_count;
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	move_right(t_data *vars)
{
	if (vars->map[vars->player_x][vars->player_y + 1] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_x += TILE_SIZE;
		vars->player_y += 1;
		++vars->move_count;
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	move_left(t_data *vars)
{
	if (vars->map[vars->player_x][vars->player_y - 1] != '1')
	{
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
				vars->display_x, vars->display_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
				vars->display_x, vars->display_y);
		if (vars->map[vars->player_x][vars->player_y] != 'E')
			vars->map[vars->player_x][vars->player_y] = '0';
		vars->display_x -= TILE_SIZE;
		vars->player_y -= 1;
		++vars->move_count;
		if (vars->map[vars->player_x][vars->player_y] == '0')
			vars->map[vars->player_x][vars->player_y] = 'P';
		if (vars->map[vars->player_x][vars->player_y] == 'C')
		{
			vars->map[vars->player_x][vars->player_y] = '0';
			vars->collected++;
		}
		ft_printf("\n%d\n", vars->move_count);
	}
}

void	check_exit(t_data *vars)
{
	if (vars->map[vars->player_x][vars->player_y] == 'E'
		&& vars->collected == vars->count.collectible_count)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
			vars->display_x, vars->display_y);
		ft_printf("\nyou win!\n");
		ft_exit(vars);
	}
	else if (vars->map[vars->player_x][vars->player_y] == 'E'
			&& vars->collected != vars->count.collectible_count)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
			vars->display_x, vars->display_y);
		ft_printf("\nyou have to collect all the eggs before you go!\n");
	}
}

int	player_move(int keycode, t_data *vars)
{
	if (keycode == XK_Escape)
		ft_esckey(vars);
	if (keycode == XK_w || keycode == XK_Up)
	{
		move_up(vars);
		check_exit(vars);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		move_right(vars);
		check_exit(vars);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		move_down(vars);
		check_exit(vars);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		move_left(vars);
		check_exit(vars);
	}
	return (1);
}
int	main(int argc, char *argv[])
{
	t_data data;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid argument!\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(data));
	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		ft_printf("Error: MLX initialization failed\n");
		free_data(&data);
		exit(EXIT_FAILURE);
	}
	data.map_name = argv[1];
	ft_readmap(&data);
	data.win = mlx_new_window(data.mlx,data.width * TILE_SIZE, data.height* TILE_SIZE, "so_long");
	if (data.win == NULL)
	{
		ft_printf("Error: Failed to create window.\n");
		free_data(&data);
		exit(EXIT_FAILURE);
	}
	ft_loadimages(&data);
	ft_displayimage(&data);
	mlx_hook(data.win,17,0,ft_esckey,&data);
	mlx_hook(data.win, 2, 1L << 0, player_move, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	free_data(&data);
	return (0);
}
