/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 01:01:56 by tlee              #+#    #+#             */
/*   Updated: 2024/11/06 22:10:32 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
#include "./src/libft/libft.h"
#include "./src/ft_printf/ft_printf.h"
#include "./src/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

/*
typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		diamonds;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_data;
*/
#define TILE_SIZE 100

typedef struct s_images
{
	char		*floor;
	char		*wall;
	char		*exit;
	char		*gem;
	char		*player;
}	t_images;

typedef struct s_count
{
	int	player_count;
	int exit_count;
	int collectible_count;
}	t_count;

typedef struct s_data
{
	t_images	img;
	t_count		count;
	char		**map;
	char		*map_name;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			move_count;
	int			collected;
	int			display_x;
	int			display_y;
	int			player_x;
	int			player_y;
}	t_data;





void ft_readmap(t_data *data);
void free_data(t_data *data);
void ft_loadimages(t_data *data);
void ft_displayimage(t_data *data);