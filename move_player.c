/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <axbaudri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:05:38 by axbaudri          #+#    #+#             */
/*   Updated: 2025/07/28 12:32:12 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->lines[y - 1][x] != '1' &&
		!(game->lines[y - 1][x] == 'E' && game->count > 0))
	{
		if (game->lines[y - 1][x] == 'C')
			game->count--;
		else if (game->lines[y - 1][x] == 'E' && game->count == 0)
			close_win(&game->so_long);
		game->lines[y - 1][x] = 'P';
		game->lines[y][x] = '0';
		game->player->y--;
		game->step++;
		ft_printf("Step = %d, Count = %d\n", game->step, game->count);
	}
}

void	move_to_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->lines[y][x - 1] != '1' &&
		!(game->lines[y][x - 1] == 'E' && game->count > 0))
	{
		if (game->lines[y][x - 1] == 'C')
			game->count--;
		else if (game->lines[y][x - 1] == 'E' && game->count == 0)
			close_win(&game->so_long);
		game->lines[y][x - 1] = 'P';
		game->lines[y][x] = '0';
		game->player->x--;
		game->step++;
		ft_printf("Step = %d, Count = %d\n", game->step, game->count);
	}
}

void	move_to_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->lines[y + 1][x] != '1' &&
		!(game->lines[y + 1][x] == 'E' && game->count > 0))
	{
		if (game->lines[y + 1][x] == 'C')
			game->count--;
		else if (game->lines[y + 1][x] == 'E' && game->count == 0)
			close_win(&game->so_long);
		game->lines[y + 1][x] = 'P';
		game->lines[y][x] = '0';
		game->player->y++;
		game->step++;
		ft_printf("Step = %d, Count = %d\n", game->step, game->count);
	}
}

void	move_to_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (game->lines[y][x + 1] != '1' &&
		!(game->lines[y][x + 1] == 'E' && game->count > 0))
	{
		if (game->lines[y][x + 1] == 'C')
			game->count--;
		else if (game->lines[y][x + 1] == 'E' && game->count == 0)
			close_win(&game->so_long);
		game->lines[y][x + 1] = 'P';
		game->lines[y][x] = '0';
		game->player->x++;
		game->step++;
		ft_printf("Step = %d, Count = %d\n", game->step, game->count);
	}
}
