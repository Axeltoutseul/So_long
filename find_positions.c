/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:56:02 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/02 19:21:16 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	*player_position(char **strs)
{
	t_pos	*player;
	int		i;
	int		j;

	i = 0;
	player = (t_pos *)malloc(sizeof(t_pos));
	if (!count_occurrences(strs, 'P') || !count_occurrences(strs, 'C')
		|| !count_occurrences(strs, 'E') || !player)
		return (free(player), NULL);
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
	return (player);
}

t_pos	*exit_position(char **strs)
{
	t_pos	*quit;
	int		i;
	int		j;

	i = 0;
	quit = (t_pos *)malloc(sizeof(t_pos));
	if (!count_occurrences(strs, 'P') || !count_occurrences(strs, 'C')
		|| !count_occurrences(strs, 'E') || !quit)
		return (free(quit), NULL);
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == 'E')
			{
				quit->x = j;
				quit->y = i;
			}
			j++;
		}
		i++;
	}
	return (quit);
}

int	is_in_map(t_game *game, int carac)
{
	int	i;
	int	j;

	i = 0;
	while (game->lines[i])
	{
		j = 0;
		while (game->lines[i][j])
		{
			if (game->lines[i][j] == carac)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	unfinishable(t_game *game)
{
	int		result;

	result = 0;
	flood_fill(game->copy, game->player->x, game->player->y);
	if (count_occurrences(game->copy, 'C') > 0
		|| count_occurrences(game->copy, 'E') > 0)
		result = 1;
	return (result);
}
