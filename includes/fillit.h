/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:30:52 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 19:45:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include "libft.h"

int		ft_check_tetriminos(t_list *list);
int		ft_cpy_file(int fd, t_list **list);
int		ft_check_hashtag(t_list *list);
char	**ft_save_tetris(t_list **list, size_t counter);
t_list	*ft_list_tetris(t_list *list);
void	ft_lstcustom_clean(t_list **a_lst);
int		ft_solver(char tab[30][30], t_list *tetris, int lc[2], int *size);
void	ft_init_tab(char tab[30][30], int size);
void	ft_cpy_tab(char dst[30][30], char src[30][30], int size);
void	ft_main_solver(t_list *tetris, int size);
int		ft_trytetris(char tab[30][30], int lc[2], int size, t_list *tetris);

#endif
