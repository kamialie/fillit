/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:50:13 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/16 15:58:59 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_size_tetramino(char *str, int *a)
{
	int			i;

	i = 0;
	a[0] = 3;
	a[1] = 0;
	a[2] = 3;
	a[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < a[0])
				a[0] = i % 5;
			if (i % 5 > a[1])
				a[1] = i % 5;
			if (i / 5 < a[2])
				a[2] = i / 5;
			if (i / 5 > a[3])
				a[3] = i / 5;
		}
		i++;
	}
}

t_tetr			*ft_tetrnew(unsigned short int content, char c, char *buf)
{
	t_tetr		*new;
	int			a[4];

	if (!(new = (t_tetr *)malloc(sizeof(*new))))
		return (NULL);
	new->tetramino = content;
	new->letter = c;
	new->x = 0;
	new->y = 0;
	ft_size_tetramino(buf, a);
	new->length = a[1] - a[0] + 1;
	new->width = a[3] - a[2] + 1;
	new->next = NULL;
	return (new);
}

void			ft_push_back(t_tetr **head, t_tetr *new)
{
	t_tetr		*tmp;

	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int				ft_count_list(t_tetr *head)
{
	int			i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void			ft_free_list(t_tetr **head)
{
	t_tetr	*tmp;

	if (*head == NULL)
		return ;
	while (*head != NULL)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
	*head = NULL;
}
