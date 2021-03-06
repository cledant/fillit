/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:15:33 by cledant           #+#    #+#             */
/*   Updated: 2015/11/27 19:54:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*cpy_result;
	size_t	index;
	size_t	counter;

	counter = 0;
	index = start;
	result = ft_strnew(len + 1);
	if (result == NULL)
		return (result);
	cpy_result = result;
	while (counter < len)
	{
		*result = s[index];
		counter++;
		result++;
		index++;
	}
	*result = '\0';
	return (cpy_result);
}
