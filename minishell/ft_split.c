/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:59:09 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 16:14:12 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	howmuchchar(char *s, char c)
{
	int	i;
	int	count;
	int	stryet;

	stryet = 0;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			stryet = 1;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && stryet == 1)
			count++;
		i++;
	}
	return (count + 1);
}

static size_t	lenstr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*putstring(char *s, char c)
{
	char	*box;
	size_t	i;

	i = 0;
	box = malloc(sizeof(char) * (lenstr(s, c) + 1));
	if (!box)
		return (NULL);
	while (i < lenstr(s, c))
	{
		box[i] = s[i];
		i++;
	}
	box[i] = '\0';
	return (box);
}

char	**ft_split(char const *s, char c)
{
	char	**box;
	int		i;
	int		z;

	z = 0;
	i = 0;
	if (!s)
		return (NULL);
	box = malloc(sizeof(char *) * (howmuchchar((char *)s, c) + 1));
	if (!box)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			box[z] = putstring((char *)&s[i], c);
			z++;
		}
		i++;
	}
	box[z] = 0;
	return (box);
}
