/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:19:55 by cledant           #+#    #+#             */
/*   Updated: 2015/12/06 14:28:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include "libft.h"

static int		ft_skip_resize(t_list *tetris)
{
	int		size;
	int		tetris_nb;

	tetris_nb = 0;
	size = 0;
	while (tetris != NULL)
	{
		tetris_nb++;
		tetris = tetris->next;
	}
	tetris_nb = tetris_nb * 4;
	while (tetris_nb > (size * size))
		size++;
	return (size);
}

static int		ft_resize(int lc[2], int size)
{
	if (lc[0] >= size)
	{
		lc[0] = 0;
		lc[1]++;
		if (lc[1] >= size)
		{
			lc[0] = 0;
			lc[1] = 0;
			size++;
		}
	}
	return (size);
}

void			ft_main_solver(t_list *tetris, int size)
{
	int		lc[2];
	int		cpy_lc[2];
	char	v_tab[30][30];
	t_list	*cpy_tetris;
	int		ret;

	ret = 0;
	cpy_tetris = tetris;
	ft_bzero(lc, 2 * sizeof(int));
	ft_bzero(cpy_lc, 2 * sizeof(int));
	size = ft_skip_resize(cpy_tetris);
	ft_init_tab(v_tab, size);
	while (ret == 0)
	{
		ft_memcpy(cpy_lc, lc, 2 * sizeof(int));
		ret = ft_solver(v_tab, tetris, lc, &size);
		ft_memcpy(lc, cpy_lc, 2 * sizeof(int));
		lc[0]++;
		size = ft_resize(lc, size);
		ft_init_tab(v_tab, size);
	}
}
