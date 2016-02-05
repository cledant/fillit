/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:50:17 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 17:47:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include "libft.h"

void	ft_init_tab(char tab[30][30], int size)
{
	int		l;
	int		c;

	c = 0;
	l = 0;
	while (l < size)
	{
		while (c < size)
		{
			if (c == size)
				tab[l][c] = '\0';
			else
				tab[l][c] = '.';
			c++;
		}
		c = 0;
		l++;
	}
}
