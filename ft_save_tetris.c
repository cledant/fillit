/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:05:24 by cledant           #+#    #+#             */
/*   Updated: 2015/12/05 08:51:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

char	**ft_save_tetris(t_list **list, size_t counter)
{
	char	**square;
	char	**cpy_square;

	square = (char **)malloc(5 * sizeof(char *));
	if (square == NULL)
		return (square);
	cpy_square = square;
	ft_bzero(square, 5 * sizeof(char *));
	while (counter < 4)
	{
		*square = (char *)malloc(5 * sizeof(char));
		if (*square == NULL)
		{
			free(square);
			return (NULL);
		}
		ft_bzero(*square, 5);
		ft_memmove(*square, (*list)->content, 4);
		(*list) = (*list)->next;
		counter++;
		square++;
	}
	if ((*list)->content_size != 0)
		(*list) = (*list)->next;
	return (cpy_square);
}
