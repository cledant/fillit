/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:18:47 by cledant           #+#    #+#             */
/*   Updated: 2015/11/25 10:44:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;
	void	*cpy_dst;

	counter = 0;
	cpy_dst = dst;
	while (counter < n)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		counter++;
	}
	return (cpy_dst);
}
