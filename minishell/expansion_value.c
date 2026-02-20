/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:33:41 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 16:52:02 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool ft_strcmp_till_equal(char *str, char *str2)
{
	int i;
	
	i = 0;
	if (str == NULL || str[0] == '\0' || !str)
		return (0);
	while (str[i] != '\0' && str[i] != '=')
	{
		if (str[i] != str2[i] || str[i] == '\0' || str2[i] == '\0')
			return (false);
		i++;
	}
	if (i != len_split(str2))
		return (false);
	return (true);
}

char *cut_value_env(char *env_str)
{
	int i;

	i = 0;
	while (env_str[i] != '\0')
	{
		if (env_str[i] == '=')
		{
			i++;
			return (&env_str[i]);
		}
		i++;
	}
	return (NULL);
}

char *find_env(char **env, char *str)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp_till_equal(env[i], str) == true)
			return (cut_value_env(env[i]));
		i++;
	}
	return (NULL);
}
