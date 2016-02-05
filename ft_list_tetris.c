/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:34:00 by cledant           #+#    #+#             */
/*   Updated: 2015/12/05 10:13:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

static t_list	*ft_custom_list(char **tetris, size_t nbr)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = tetris;
	new->content_size = nbr;
	new->next = NULL;
	return (new);
}

t_list			*ft_list_tetris(t_list *list)
{
	t_list		*first;
	t_list		*new;
	size_t		counter;

	counter = 0;
	first = ft_custom_list(ft_save_tetris(&list, 0), counter);
	if (first == NULL)
		return (NULL);
	counter++;
	while (list->content_size != 0)
	{
		new = ft_custom_list(ft_save_tetris(&list, 0), counter);
		if (new == NULL)
		{
			ft_lstcustom_clean(&first);
			return (NULL);
		}
		counter++;
		ft_lstpushback(first, new);
	}
	return (first);
}
