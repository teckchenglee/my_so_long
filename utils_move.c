/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:18:05 by tlee              #+#    #+#             */
/*   Updated: 2024/11/07 21:54:46 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_data *vars, int x_offset, int y_offset)
{
    int new_x = vars->player_x + x_offset;
    int new_y = vars->player_y + y_offset;

    // Check if the new position is within bounds of the map
    if (new_x >= 0 && new_x < vars->height && new_y >= 0 && new_y < vars->width)
    {
        // Check if the new position is not a wall ('1')
        if (vars->map[new_x][new_y] != '1')
        {
            // If not on exit ('E'), set the current tile to floor ('0') and update window
            if (vars->map[vars->player_x][vars->player_y] != 'E')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor, vars->display_x, vars->display_y);
            else
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, vars->display_x, vars->display_y);

            // If current tile is not exit ('E'), mark it as empty ('0')
            if (vars->map[vars->player_x][vars->player_y] != 'E')
                vars->map[vars->player_x][vars->player_y] = '0';

            // Update player position
            vars->player_x = new_x;
            vars->player_y = new_y;
            vars->display_x += x_offset * TILE_SIZE;
            vars->display_y += y_offset * TILE_SIZE;

            ++vars->move_count;

            // Handle new tile (if it's empty or a collectible)
            if (vars->map[vars->player_x][vars->player_y] == '0')
                vars->map[vars->player_x][vars->player_y] = 'P';
            
            if (vars->map[vars->player_x][vars->player_y] == 'C')
            {
                vars->map[vars->player_x][vars->player_y] = '0';
                vars->collected++;
            }

            ft_printf("\nMove count: %d\n", vars->move_count);
        }
    }
}

// Movement functions simplified
void move_up(t_data *vars)
{
    move_player(vars, -1, 0);  // Move up (decrease x)
}

void move_down(t_data *vars)
{
    move_player(vars, 1, 0);   // Move down (increase x)
}

void move_right(t_data *vars)
{
    move_player(vars, 0, 1);   // Move right (increase y)
}

void move_left(t_data *vars)
{
    move_player(vars, 0, -1);  // Move left (decrease y)
}
