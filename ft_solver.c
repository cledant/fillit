/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:21:58 by cledant           #+#    #+#             */
/*   Updated: 2015/12/06 14:27:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include "libft.h"

static void		ft_printtab(char tab[30][30], int size)
{
	int		c;
	int		l;

	c = 0;
	l = 0;
	while (l < size)
	{
		while (c < size)
		{
			ft_putchar(tab[l][c]);
			c++;
		}
		ft_putchar('\n');
		c = 0;
		l++;
	}
}

static int		ft_solver_case1(char tab[30][30], t_list *tetris, int lc[2],
					int *size)
{
	int ret;

	ret = 0;
	tetris = tetris->next;
	if (tetris != NULL)
	{
		lc[1] = 0;
		lc[0] = 0;
		ret = ft_solver(tab, tetris, lc, size);
	}
	if (tetris == NULL)
	{
		ft_printtab(tab, *size);
		return (1);
	}
	return (ret);
}

static int		ft_raise_lc(int lc[2], int *size)
{
	if (lc[0] >= *size)
	{
		lc[0] = 0;
		lc[1]++;
		if (lc[1] >= *size)
			return (1);
	}
	return (0);
}

int				ft_solver(char tab[30][30], t_list *tetris, int lc[2],
					int *size)
{
	int		ret;
	char	cpy[30][30];
	int		cpy_lc[2];
	t_list	*cpy_tetris;

	cpy_tetris = tetris;
	ft_memcpy(cpy_lc, lc, 2 * sizeof(int));
	ret = 0;
	ft_cpy_tab(cpy, tab, *size);
	if (ft_trytetris(tab, lc, *size, tetris) == 1 && tetris != NULL)
		ret = ft_solver_case1(tab, tetris, lc, size);
	if (tetris != NULL && ret == 0)
	{
		ft_memcpy(lc, cpy_lc, 2 * sizeof(int));
		tetris = cpy_tetris;
		lc[0]++;
		if (ft_raise_lc(lc, size) == 1)
			return (0);
		ft_cpy_tab(tab, cpy, *size);
		if (tetris != NULL)
			ret = ft_solver(tab, tetris, lc, size);
	}
	return (ret);
}
