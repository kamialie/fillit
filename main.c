/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:54:38 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/16 15:58:52 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_read(char *str, t_tetr **head)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE];
	int			check;
	int			count;

	count = 0;
	fd = open(str, O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		check = ret;
		if (ret >= BUFF_SIZE - 2 && (ft_read_and_check(buf, ret)))
			ft_push_back(&(*head),
					ft_tetrnew(ft_char_to_bit(buf), ('A' + count), buf));
		else
			return (0);
		count++;
	}
	if (check != 20)
		return (0);
	if (count > 27 || head == NULL)
		return (0);
	return (1);
}

int				main(int args, char **argv)
{
	int			ret;
	t_tetr		*head;

	head = NULL;
	if (args == 2)
	{
		if (!(ret = ft_read(argv[1], &head)))
			ft_putstr("error\n");
		else
			ft_solve(&head);
		ft_free_list(&head);
	}
	else
		ft_putstr("usage: ./fillit input_file\n");
	return (0);
}
