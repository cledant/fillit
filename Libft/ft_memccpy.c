/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:18:47 by cledant           #+#    #+#             */
/*   Updated: 2015/11/26 13:28:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	counter;
	void	*cpy_dst;

	counter = 0;
	cpy_dst = dst;
	while (counter < n)
	{
		*(char *)dst = *(char *)src;
		if (*(unsigned char *)dst == (unsigned char)c)
			return (dst + 1);
		dst++;
		src++;
		counter++;
	}
	return (0);
}
