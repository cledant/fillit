/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hashtag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:05:24 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 17:45:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

static int		ft_check_counter(size_t *tab)
{
	size_t	counter;
	size_t	nbr_1;

	counter = 0;
	nbr_1 = 0;
	while (counter < 4)
	{
		if (tab[counter] == 0)
			return (-1);
		if (tab[counter] == 1)
			nbr_1++;
		counter++;
	}
	if (nbr_1 == 4)
		return (-1);
	return (0);
}

static size_t	ft_check_closeone(char **square, int l, int c)
{
	int		nbr;

	nbr = 0;
	if (l - 1 >= 0)
		if (square[l - 1][c] == '#')
			nbr++;
	if (c - 1 >= 0)
		if (square[l][c - 1] == '#')
			nbr++;
	if (c + 1 < 4)
		if (square[l][c + 1] == '#')
			nbr++;
	if (l + 1 < 4)
		if (square[l + 1][c] == '#')
			nbr++;
	return (nbr);
}

static int		ft_check_link(char **s)
{
	size_t	count;
	size_t	counter[4];
	int		c;
	int		l;

	c = 0;
	l = 0;
	count = 0;
	ft_bzero(counter, 4 * sizeof(size_t));
	while (l < 4)
	{
		while (c < 4)
		{
			if (s[l][c] == '#')
			{
				counter[count] = ft_check_closeone(s, l, c);
				count++;
			}
			c++;
		}
		c = 0;
		l++;
	}
	return (ft_check_counter(counter));
}

static int		ft_check_nbr(char **s)
{
	int		c;
	int		l;
	size_t	counter_h;

	counter_h = 0;
	c = 0;
	l = 0;
	while (l < 4)
	{
		while (c < 4)
		{
			if (s[l][c] == '#')
				counter_h++;
			c++;
		}
		c = 0;
		l++;
	}
	if (counter_h != 4)
		return (-1);
	return (0);
}

int				ft_check_hashtag(t_list *list)
{
	char	**square;
	t_list	*cpy_list;

	cpy_list = list;
	while (list->content_size != 0)
	{
		square = ft_save_tetris(&list, 0);
		if (square == NULL)
			return (-1);
		if (ft_check_nbr(square) == -1)
		{
			free(square);
			return (-1);
		}
		if (ft_check_link(square) == -1)
		{
			free(square);
			return (-1);
		}
		free(square);
	}
	list = cpy_list;
	return (0);
}
