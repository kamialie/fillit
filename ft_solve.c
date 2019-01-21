/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:41:37 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/15 18:30:40 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short int		ft_get_map_piece(int x, int y,
									unsigned short int *map)
{
	int							i;
	unsigned short int			piece;
	unsigned short int			line;
	unsigned short int			mask;

	piece = 0;
	i = 0;
	while (i < 4)
	{
		mask = ((1 << 4) - 1) << (12 - x);
		line = map[y + i] & mask;
		line = line << x;
		line = line >> i * 4;
		piece |= line;
		i++;
	}
	return (piece);
}

static void						ft_turn_on_off(unsigned short int **map,
									unsigned short int tetramino, int x, int y)
{
	int							i;
	unsigned short int			mask;
	unsigned short int			line;

	i = 0;
	while (i < 4)
	{
		mask = ((1 << 4) - 1) << (12 - (i * 4));
		line = tetramino & mask;
		line = line << i * 4;
		line = line >> x;
		*(*map + y + i) ^= line;
		i++;
	}
}

static int						ft_tetris(unsigned short int *map,
									t_tetr *head, int limit)
{
	int							x;
	int							y;

	if (head == NULL)
		return (1);
	y = 0;
	while (y + head->width <= limit)
	{
		x = 0;
		while (x + head->length <= limit)
		{
			if (!(head->tetramino & ft_get_map_piece(x, y, map)))
			{
				ft_turn_on_off(&map, head->tetramino, x, y);
				head->x = x;
				head->y = y;
				if (ft_tetris(map, head->next, limit))
					return (1);
				ft_turn_on_off(&map, head->tetramino, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void							ft_solve(t_tetr **head)
{
	unsigned short int			*map;
	int							size;

	size = 2;
	map = (unsigned short int *)malloc(sizeof(*map) * 16);
	ft_bzero(map, 16);
	while (size * size < 4 * ft_count_list(*head))
		size++;
	while (!ft_tetris(map, *head, size) && size <= 16)
	{
		ft_bzero(map, 16);
		size++;
	}
	free(map);
	ft_print(*head, size);
}
