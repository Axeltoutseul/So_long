/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:04:12 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/03 18:10:49 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_lines(char **lines, char **copy)
{
	int	i;

	i = 0;
	if (!lines || !copy)
		return ;
	while (lines[i])
		free(lines[i++]);
	free(lines);
	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

void	free_pictures(t_data **pictures, int size)
{
	int	i;

	i = 0;
	if (!pictures)
		return ;
	while (i < size)
		free(pictures[i++]);
	free(pictures);
}

void	free_map(t_game *game)
{
	free(game->player);
	free(game->quit);
	free(game->content);
	free_lines(game->lines, game->copy);
}

void	free_window(t_vars *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
}
