/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcustom_clean.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:34:00 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 18:48:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

void	ft_lstcustom_clean(t_list **alst)
{
	t_list	**ptr_first;
	t_list	*previous_lst;

	ptr_first = alst;
	*ptr_first = *alst;
	while (*alst != NULL)
	{
		free((*alst)->content);
		previous_lst = *alst;
		*alst = (*alst)->next;
		free(previous_lst);
	}
	free(*ptr_first);
	*ptr_first = NULL;
}
