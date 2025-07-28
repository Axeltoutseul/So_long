/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:31:15 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/04 11:30:32 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_strings2(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != c && str[0] != '\0')
	{
		count++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && (str[i + 1] != c && str[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

int	close_win(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player->x;
	y = game->player->y;
	if (keycode == XK_W || keycode == XK_w)
		modify_text(keycode, game);
	if (keycode == XK_A || keycode == XK_a)
		modify_text(keycode, game);
	if (keycode == XK_S || keycode == XK_s)
		modify_text(keycode, game);
	if (keycode == XK_D || keycode == XK_d)
		modify_text(keycode, game);
	if (keycode == XK_Escape)
		close_win(&game->so_long);
	free_pictures(game->pictures, game->size_y);
	game->pictures = draw_map(game);
	return (0);
}

int	is_ber(char *filename)
{
	int		i;
	int		result;

	i = 0;
	result = 1;
	while (filename[i] != '.')
		i++;
	if (!(filename + i)
		|| ft_strncmp(filename + i, ".ber", ft_strlen(filename + i)) != 0)
		result = 0;
	return (result);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	fd = open(argv[1], O_RDWR);
	if (argc != 2 || fd == -1)
		ft_printf("Error\nYou must enter a valid path\n");
	else
	{
		game = init_map(fd, argv[1]);
		if (is_valid(game, argv[1]))
		{
			game->so_long.mlx = mlx_init();
			game->so_long.win = mlx_new_window(game->so_long.mlx,
					game->size_x * 40, game->size_y * 40, "New window");
			game->pictures = draw_map(game);
			mlx_hook(game->so_long.win, ON_KEYDOWN, 1L << 0, handle_key, game);
			mlx_hook(game->so_long.win, 17, 1L << 5, close_win, &game->so_long);
			mlx_loop(game->so_long.mlx);
			free_pictures(game->pictures, game->size_y);
			free_window(&game->so_long);
		}
		free_map(game);
		free(game);
	}
	return (0);
}
