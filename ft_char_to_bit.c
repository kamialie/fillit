/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:21:05 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/15 15:06:50 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short int	ft_power_of_two(int power)
{
	int						i;

	if (!power)
		return (1);
	i = 1;
	while (power-- > 0)
		i *= 2;
	return (i);
}

unsigned short int			ft_char_to_bit(char *tetramino)
{
	unsigned short			a;
	int						i;
	int						j;

	a = 0;
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (tetramino[i] == '#')
			a |= ft_power_of_two(15 - j);
		if (tetramino[i] != '\n')
			j++;
		i++;
	}
	while (!(a & 0xF000))
		a = a << 4;
	while (!(a & 0x8888))
		a = a << 1;
	return (a);
}
