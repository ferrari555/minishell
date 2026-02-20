/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:59:09 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 16:16:59 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	len_str(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s[i] == '"' && count_char(s,'"') > 1)
	{
		i++;
		while ((s[i] != '"' && s[i] != '\0'))
			i++; 
	}
	else if (s[i] == '\'' && count_char(s,'\'') > 1)
	{
		i++;
		while ((s[i] != '\'' && s[i] != '\0'))
			i++;
	}
	while (s[i] != c && s[i] != '\0')
		i++;	
	return (i - 1);
}

t_user_input	*passer(char const *s, char c, char **env)
{
	t_user_input	*box;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			if (i == 0)
				box = table_link_input(put_str_remove_quote((char *)&s[i], c, env),NULL);
			else
				box = table_link_input(put_str_remove_quote((char *)&s[i], c, env),box);
			if (s[i] == '"' || s[i] == '\'')
				i += len_str((char *)&s[i], c);
		}
		i++;
	}
	return (box);
}
