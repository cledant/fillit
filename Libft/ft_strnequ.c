/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:54:07 by cledant           #+#    #+#             */
/*   Updated: 2015/11/27 19:30:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (*s1 != '\0' && *s2 != '\0' && counter < n)
	{
		if (*s1 != *s2)
			return (0);
		counter++;
		s1++;
		s2++;
	}
	return (1);
}
