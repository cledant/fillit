/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:03:27 by cledant           #+#    #+#             */
/*   Updated: 2015/11/27 20:17:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static size_t	ft_word_len_c(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s == c)
	{
		if (*s == '\0')
			return (result);
		s++;
	}
	while (*s != '\0')
	{
		if (*s == c)
			return (result);
		result++;
		s++;
	}
	return (result);
}

static char		*ft_isolate_c(char const *s, char c, char *result)
{
	char	*cpy_result;

	if (ft_strlen(s) == ft_word_len_c(s, c))
		return ((char *)s);
	else
	{
		cpy_result = result;
		while (*s == c)
		{
			if (*s == '\0')
				return (cpy_result);
			s++;
		}
		while (*s != '\0')
		{
			if (*s == c)
				return (cpy_result);
			*result = *s;
			s++;
			result++;
		}
	}
	return (cpy_result);
}

static size_t	ft_word_count(char *s, char c, size_t result)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
			{
				if (*s == '\0')
					return (result);
				s++;
			}
		}
		else
		{
			result++;
			while (*s != c)
			{
				if (*s == '\0')
					return (result);
				s++;
			}
		}
	}
	return (result);
}

static char		*ft_move_s(char *s, char c)
{
	while (*s == c)
	{
		if (*s == '\0')
			return (s);
		s++;
	}
	while (*s != c)
	{
		if (*s == '\0')
			return (s);
		s++;
	}
	return (s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	char	**cpy_res;
	size_t	words;
	size_t	counter;

	counter = 0;
	words = 0;
	words = ft_word_count((char *)s, c, words);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (result);
	ft_bzero(result, words + 1);
	cpy_res = result;
	while (counter < words)
	{
		*result = ft_strnew(ft_word_len_c(s, c) + 1);
		if (*result == NULL)
			return (result);
		*result = ft_isolate_c(s, c, *result);
		s = ft_move_s((char *)s, c);
		counter++;
		result++;
	}
	return (cpy_res);
}
