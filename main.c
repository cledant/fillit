/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:59:04 by cledant           #+#    #+#             */
/*   Updated: 2015/12/05 10:34:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft.h"

static	t_list	*ft_open_main(int fd, char **argv, int error, t_list **list)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	error = ft_cpy_file(fd, list);
	if (error == -1)
	{
		close(fd);
		ft_putendl("error");
		return (NULL);
	}
	fd = close(fd);
	if (fd == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	return (*list);
}

static t_list	*ft_main_next(t_list *list, t_list **tetris, int error)
{
	error = ft_check_tetriminos(list);
	if (error == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	error = ft_check_hashtag(list);
	if (error == -1)
	{
		ft_putendl("error");
		return (NULL);
	}
	*tetris = ft_list_tetris(list);
	if (tetris == NULL)
	{
		ft_putendl("error");
		return (NULL);
	}
	return (*tetris);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		error;
	t_list	*list;
	t_list	*tetris;

	error = 0;
	fd = 0;
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	list = ft_open_main(fd, argv, error, &list);
	if (list == NULL)
		return (-1);
	tetris = ft_main_next(list, &tetris, error);
	if (tetris == NULL)
		return (-1);
	ft_main_solver(tetris, 2);
	ft_lstdel(&list, &ft_bzero);
	ft_lstcustom_clean(&tetris);
	return (0);
}
