/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:11:28 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 17:56:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putendln(char const *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		ft_putchar(*s);
		counter++;
		s++;
	}
	ft_putchar('\n');
}
