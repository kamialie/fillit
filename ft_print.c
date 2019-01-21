/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:34:34 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/16 12:29:47 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				ft_create(t_print *a, t_tetr *figure, int size)
{
	a->grill = 4;
	a->mask = 0x8000;
	a->i = 0;
	a->x = figure->x + figure->y * size;
}

void					ft_print(t_tetr *figure, int size)
{
	t_print				a;
	char				*map;

	map = ft_create_map(size++);
	while (figure)
	{
		ft_create(&a, figure, size);
		while (a.grill)
		{
			if (figure->tetramino & a.mask)
			{
				map[a.x] = figure->letter;
				(a.grill)--;
			}
			a.mask = a.mask >> 1;
			(a.i)++;
			if ((a.i) % 4 == 0)
				a.x = figure->x + figure->y * size + size * ((a.i) / 4);
			else
				(a.x)++;
		}
		figure = figure->next;
	}
	ft_putstr(map);
	ft_delete_map(&map);
}
