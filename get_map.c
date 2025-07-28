/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:32:45 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/04 11:30:53 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_characters(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
		ft_printf("%s\n", strs[i++]);
}

void	flood_fill(char **lines, int x, int y)
{
	if (lines[y][x] == '1' || lines[y][x] == 'F')
		return ;
	lines[y][x] = 'F';
	flood_fill(lines, x - 1, y);
	flood_fill(lines, x + 1, y);
	flood_fill(lines, x, y - 1);
	flood_fill(lines, x, y + 1);
	return ;
}

void	modify_text(int key_code, t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (key_code == XK_W || key_code == XK_w)
		move_to_up(game);
	if (key_code == XK_A || key_code == XK_a)
		move_to_left(game);
	if (key_code == XK_S || key_code == XK_s)
		move_to_down(game);
	if (key_code == XK_D || key_code == XK_d)
		move_to_right(game);
}

int	has_an_empty_line(char *content)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (content[i])
	{
		if (content[i] == '\n' && content[i + 1] == '\n')
			result = 1;
		i++;
	}
	return (result);
}
