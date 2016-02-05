/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trytetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:21:58 by cledant           #+#    #+#             */
/*   Updated: 2015/12/05 10:22:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include "libft.h"

static int		ft_trytetris_one(int int_tab[5], int lc[2], char tab[30][30],
					t_list *tetris)
{
	if (tab[lc[1]][lc[0]] < 'A' || tab[lc[1]][lc[0]] > 'Z')
	{
		tab[lc[1]][lc[0]] = 'A' + tetris->content_size;
		int_tab[3] = int_tab[1];
		int_tab[4] = int_tab[2];
		int_tab[0]++;
	}
	else
		return (0);
	return (1);
}

static void		ft_trytetris_two(int int_tab[5], int lc[2], char tab[30][30],
					t_list *tetris)
{
	if ((lc[1] - int_tab[4] + int_tab[2]) >= 0 &&
		(lc[1] - int_tab[4] + int_tab[2]) < int_tab[5])
		if ((lc[0] - int_tab[3] + int_tab[1]) >= 0 &&
			(lc[0] - int_tab[3] + int_tab[1]) < int_tab[5])
			if (tab[lc[1] - int_tab[4] + int_tab[2]][lc[0] -
				int_tab[3] + int_tab[1]] < 'A' ||
				tab[lc[1] - int_tab[4] + int_tab[2]][lc[0] -
				int_tab[3] + int_tab[1]] > 'Z')
			{
				tab[lc[1] - int_tab[4] + int_tab[2]][lc[0] -
					int_tab[3] + int_tab[1]] = 'A' +
					tetris->content_size;
				int_tab[0]++;
			}
}

static int		ft_trytetris_three(int int_tab[5], int lc[2], char tab[30][30],
					t_list *tetris)
{
	char	**tab_tetris;

	tab_tetris = tetris->content;
	while (int_tab[2] < 4)
	{
		while (int_tab[1] < 4)
		{
			if (tab_tetris[int_tab[2]][int_tab[1]] == '#')
			{
				if (int_tab[0] == 0)
				{
					if (ft_trytetris_one(int_tab, lc, tab, tetris) == 0)
						return (0);
				}
				else
					ft_trytetris_two(int_tab, lc, tab, tetris);
			}
			int_tab[1]++;
		}
		int_tab[1] = 0;
		int_tab[2]++;
	}
	return (1);
}

int				ft_trytetris(char tab[30][30], int lc[2], int size,
					t_list *tetris)
{
	int		t_lc[2];
	int		p_t_lc[2];
	int		counter;
	int		int_tab[6];

	counter = 0;
	ft_bzero(t_lc, 2 * sizeof(int));
	ft_bzero(p_t_lc, 2 * sizeof(int));
	int_tab[0] = counter;
	int_tab[1] = t_lc[0];
	int_tab[2] = t_lc[1];
	int_tab[3] = p_t_lc[0];
	int_tab[4] = p_t_lc[1];
	int_tab[5] = size;
	if (ft_trytetris_three(int_tab, lc, tab, tetris) == 0)
		return (0);
	if (int_tab[0] == 4)
		return (1);
	else
		return (0);
}
