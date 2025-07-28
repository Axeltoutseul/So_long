/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:50 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/03 19:06:45 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **lines, char *content)
{
	int		i;
	int		length;
	int		result;

	i = 0;
	result = 1;
	length = ft_strlen(lines[0]);
	if (has_an_empty_line(content))
		result = 0;
	while (lines[i])
		if (ft_strlen(lines[i++]) != length)
			result = 0;
	if (i < 3 || length < 5 || i > 25 || length > 48)
		result = 0;
	return (result);
}

int	framed_by_walls(t_game *game)
{
	int	result;
	int	x;
	int	y;

	y = 0;
	result = 1;
	while (y < game->size_y)
	{
		x = 0;
		while (x < game->size_x)
		{
			if (y == 0 || y == game->size_y - 1)
			{
				if (game->lines[y][x] != '1')
					result = 0;
			}
			else
				if ((x == 0 || x == game->size_x - 1)
					&& game->lines[y][x] != '1')
					result = 0;
			x++;
		}
		y++;
	}
	return (result);
}

int	is_valid(t_game *game, char *filename)
{
	int	result;

	result = 1;
	if (!is_rectangle(game->lines, game->content) || !is_in_map(game, 'C')
		|| count_occurrences(game->lines, 'P') != 1
		|| count_occurrences(game->lines, 'E') != 1 || !framed_by_walls(game)
		|| !only_valid_characters(game->lines)
		|| unfinishable(game) || !is_ber(filename))
		result = 0;
	return (result);
}

int	only_valid_characters(char **lines)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 1;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] != 'P' && lines[i][j] != '0' && lines[i][j] != '1'
				&& lines[i][j] != 'C' && lines[i][j] != 'E')
				result = 0;
			j++;
		}
		i++;
	}
	return (result);
}

void	check_characters(t_game *game, char *filename)
{
	if (!is_ber(filename))
		ft_printf("The file must be a .ber file.\n");
	else if (!is_rectangle(game->lines, game->content))
		ft_printf("The map isn't rectangular.\n");
	else if (!framed_by_walls(game))
		ft_printf("The map must be framed by walls.\n");
	else if (count_occurrences(game->lines, 'P') != 1)
		ft_printf("The card must contain one starting point.\n");
	else if (count_occurrences(game->lines, 'E') != 1)
		ft_printf("The card must contain one exit.\n");
	else if (!is_in_map(game, 'C'))
		ft_printf("The map must contain at least one collectible item.\n");
	else if (!only_valid_characters(game->lines))
		ft_printf("At least one character is unknown.\n");
	else if (unfinishable(game))
		ft_printf("The game can't be finished.\n");
}
