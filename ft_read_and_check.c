/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:33:28 by lwyl-the          #+#    #+#             */
/*   Updated: 2018/12/15 18:25:25 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_symbol(char *tetramino, int ret)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(tetramino[i] == '#' || tetramino[i] == '.'))
				return (0);
			if (tetramino[i] == '#' && ++count > 4)
				return (0);
		}
		else if (tetramino[i] != '\n')
			return (0);
		i++;
	}
	if (ret == 21 && tetramino[20] != '\n')
		return (0);
	return (1);
}

static int	ft_check_touch(char *tetramino, int len, int *curr)
{
	int		x;
	int		y;
	int		count;

	x = len % 5;
	y = ((len + 5) / 5);
	y--;
	count = 0;
	if ((y - 1) >= 0 && tetramino[x + (y - 1) * 5] == '#')
		count++;
	if ((y + 1) < 4 && tetramino[x + (y + 1) * 5] == '#')
		count++;
	if ((x - 1) >= 0 && tetramino[x - 1 + y * 5] == '#')
		count++;
	if ((x + 1) < 4 && tetramino[x + 1 + y * 5] == '#')
		count++;
	if (curr)
		*curr += count;
	return ((count > 0) ? 1 : 0);
}

int			ft_read_and_check(char *tetramino, int ret)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	if (!(ft_check_symbol(tetramino, ret)))
		return (0);
	while (i < 20)
	{
		if (tetramino[i] == '#')
			ft_check_touch(tetramino, i, &a);
		i++;
	}
	if ((a == 6 || a == 8))
		return (1);
	else
		return (0);
}
