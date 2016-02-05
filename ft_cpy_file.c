/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:17:31 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 18:26:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_cpy(int fd, char *buff, t_list **list, int size)
{
	int		ret_read;
	t_list	*tmp;

	ret_read = read(fd, buff, size);
	if (ret_read == -1)
	{
		ft_lstdel(list, &ft_bzero);
		return (-1);
	}
	tmp = ft_lstnew(buff, ret_read);
	if (tmp == NULL)
	{
		ft_lstdel(list, &ft_bzero);
		return (-1);
	}
	ft_lstpushback(*list, tmp);
	return (ret_read);
}

int				ft_cpy_file(int fd, t_list **list)
{
	char	buff[5];
	int		ret_read;
	int		counter;

	counter = 0;
	ret_read = read(fd, buff, 5);
	*list = ft_lstnew(buff, ret_read);
	if (*list == NULL)
		return (-1);
	if (ret_read == -1)
		ft_lstdel(list, &ft_bzero);
	counter++;
	while (ret_read > 0)
	{
		while (counter != 4 && ret_read > 0)
		{
			ret_read = ft_cpy(fd, buff, list, 5);
			counter++;
		}
		counter = 0;
		if (ret_read > 0)
			ret_read = ft_cpy(fd, buff, list, 1);
	}
	return (ret_read);
}
