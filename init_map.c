/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:08:33 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/04 11:41:37 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_map(int fd, char *filename)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->content = save_text(fd);
	game->lines = ft_split(game->content, '\n');
	game->size_x = ft_strlen(game->lines[0]);
	game->size_y = count_lines(game->lines);
	game->copy = ft_split(game->content, '\n');
	game->player = player_position(game->lines);
	game->quit = exit_position(game->lines);
	game->step = 0;
	game->count = count_occurrences(game->lines, 'C');
	if (!is_valid(game, filename))
	{
		ft_printf("Error\n");
		check_characters(game, filename);
	}
	return (game);
}

t_data	attribute_sprite(t_data img, char c, t_vars vars)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	if (c == 'P')
		img.img = mlx_xpm_file_to_image(vars.mlx, PLAYER, &width, &height);
	else if (c == '0')
		img.img = mlx_xpm_file_to_image(vars.mlx, EMPTY, &width, &height);
	else if (c == '1')
		img.img = mlx_xpm_file_to_image(vars.mlx, WALL, &width, &height);
	else if (c == 'C')
		img.img = mlx_xpm_file_to_image(vars.mlx, COLLECT, &width, &height);
	else if (c == 'E')
		img.img = mlx_xpm_file_to_image(vars.mlx, EXIT, &width, &height);
	return (img);
}

t_data	**allocate_2d_map(t_game *game)
{
	t_data	**pictures;

	pictures = (t_data **)malloc(sizeof(t_data *) * game->size_y);
	if (!pictures)
		return (NULL);
	return (pictures);
}

t_data	**draw_map(t_game *game)
{
	t_data	**img;
	int		x;
	int		y;
	char	**strs;

	y = 0;
	strs = game->lines;
	img = allocate_2d_map(game);
	while (y < game->size_y)
	{
		x = 0;
		img[y] = (t_data *)malloc(sizeof(t_data) * game->size_x);
		if (!img[y])
			return (NULL);
		while (x < game->size_x)
		{
			img[y][x] = attribute_sprite(img[y][x], strs[y][x], game->so_long);
			mlx_put_image_to_window(game->so_long.mlx, game->so_long.win,
				img[y][x].img, x * 40, y * 40);
			mlx_destroy_image(game->so_long.mlx, img[y][x++].img);
		}
		y++;
	}
	return (img);
}
