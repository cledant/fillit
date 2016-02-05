/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:39:59 by cledant           #+#    #+#             */
/*   Updated: 2015/12/10 14:58:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include "libft.h"

static int		ft_check_part3(t_list **list)
{
	if ((*list)->content_size != 5)
	{
		ft_lstdel(list, &ft_bzero);
		return (-1);
	}
	return (0);
}

static int		ft_check_part1(t_list **list)
{
	size_t	counter_char;
	void	*cpy_content;

	counter_char = 0;
	if (ft_check_part3(list) == -1)
		return (-1);
	cpy_content = (*list)->content;
	while (counter_char < 4)
	{
		if (ft_strncmp((*list)->content, ".", 1) != 0 &&
				ft_strncmp((*list)->content, "#", 1) != 0)
		{
			ft_lstdel(list, &ft_bzero);
			return (-1);
		}
		counter_char++;
		((*list)->content)++;
		if (counter_char == 4 && ft_strncmp((*list)->content, "\n", 1) != 0)
		{
			ft_lstdel(list, &ft_bzero);
			return (-1);
		}
	}
	(*list)->content = cpy_content;
	return (0);
}

static int		ft_check_part2(t_list **list, size_t *counter_tetris)
{
	if ((*list)->content_size != 1)
	{
		ft_lstdel(list, &ft_bzero);
		return (-1);
	}
	if (ft_strncmp((*list)->content, "\n", 1) != 0)
	{
		ft_lstdel(list, &ft_bzero);
		return (-1);
	}
	(*counter_tetris)++;
	if (*counter_tetris >= 26)
	{
		ft_lstdel(list, &ft_bzero);
		return (-1);
	}
	return (0);
}

int				ft_check_tetriminos(t_list *list)
{
	size_t	counter_line;
	size_t	counter_tetris;
	size_t	counter_char;

	counter_char = 0;
	counter_tetris = 0;
	counter_line = 0;
	while (list != NULL)
	{
		while (counter_line < 4)
		{
			if (ft_check_part1(&list) == -1)
				return (-1);
			list = list->next;
			counter_line++;
		}
		counter_line = 0;
		if (list->content_size == 0)
			return (0);
		if (ft_check_part2(&list, &counter_tetris) == -1)
			return (-1);
		list = list->next;
	}
	return (-1);
}
