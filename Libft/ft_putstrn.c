/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:11:28 by cledant           #+#    #+#             */
/*   Updated: 2015/12/04 17:54:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putstrn(char const *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		ft_putchar(*s);
		counter++;
		s++;
	}
}
