/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbaudri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:33:51 by axbaudri          #+#    #+#             */
/*   Updated: 2024/09/04 11:51:12 by axbaudri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*save_text(int fd)
{
	char	*new_string;
	char	*temp;

	new_string = (char *)ft_calloc(1, 1);
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp)
			new_string = join_and_free(new_string, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	return (new_string);
}

int	count_lines(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	count_occurrences(char **strs, char c)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (strs[y])
	{
		x = 0;
		while (strs[y][x])
		{
			if (strs[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
