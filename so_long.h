/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:38:17 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/04 11:51:03 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PLAYER "pictures/player.xpm"
# define EMPTY "pictures/empty.xpm"
# define WALL "pictures/wall.xpm"
# define COLLECT "pictures/collect.xpm"
# define EXIT "pictures/exit.xpm"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "X11/keysym.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	char	*content;
	char	**lines;
	char	**copy;
	int		size_x;
	int		size_y;
	int		step;
	int		count;
	t_data	**pictures;
	t_pos	*player;
	t_pos	*quit;
	t_vars	so_long;
}	t_game;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

t_data	**allocate_2d_map(t_game *game);
t_data	attribute_sprite(t_data img, char c, t_vars vars);
void	background_color(t_data img, int width, int height, int color);
void	check_characters(t_game *game, char *filename);
int		close_win(t_vars *vars);
int		count_lines(char **strs);
int		count_occurrences(char **strs, char c);
int		count_strings2(char const *str, char c);
void	display_characters(char **strs);
t_data	**draw_map(t_game *game);
t_pos	*exit_position(char **strs);
void	flood_fill(char **lines, int x, int y);
int		framed_by_walls(t_game *game);
void	free_lines(char **lines, char **copy);
void	free_map(t_game *game);
void	free_pictures(t_data **pictures, int size);
void	free_window(t_vars *so_long);
int		handle_key(int keycode, t_game *game);
int		has_an_empty_line(char *content);
t_game	*init_map(int fd, char *filename);
int		is_ber(char *filename);
int		is_in_map(t_game *game, int carac);
int		is_rectangle(char **lines, char *content);
int		is_valid(t_game *game, char *filename);
void	modify_text(int key_code, t_game *game);
void	move_to_down(t_game *game);
void	move_to_left(t_game *game);
void	move_to_right(t_game *game);
void	move_to_up(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		only_valid_characters(char **lines);
t_pos	*player_position(char **strs);
void	read_content(char **strs, t_data img, t_vars so_long, t_game *game);
char	*save_text(int fd);
int		unfinishable(t_game *game);

#endif
