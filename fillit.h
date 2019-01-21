/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:00:59 by rgyles            #+#    #+#             */
/*   Updated: 2018/12/16 15:58:20 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include <fcntl.h>
# include "libft/libft.h"

typedef struct				s_tetr
{
	unsigned short int		tetramino;
	char					letter;
	int						x;
	int						y;
	int						length;
	int						width;
	struct s_tetr			*next;
}							t_tetr;

typedef struct				s_print
{
	int						x;
	int						i;
	int						grill;
	int						mask;
}							t_print;

int							ft_read_and_check(char *tetramino, int ret);
unsigned short int			ft_char_to_bit(char *tetramino);
char						*ft_create_map(int size);
void						ft_delete_map(char **map);
t_tetr						*ft_tetrnew(unsigned short int content,
								char c, char *buf);
void						ft_push_back(t_tetr **head, t_tetr *new);
void						ft_solve(t_tetr **head);
int							ft_count_list(t_tetr *head);
void						ft_print(t_tetr *figure, int size);
void						ft_free_list(t_tetr **head);

#endif
