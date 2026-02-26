/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 00:33:41 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/26 20:20:03 by ferrarinara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char *find_env(t_env *env, char *str)
{
	t_env *tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp_bool(tmp->name, str) == true)
			return (tmp->str);
		tmp = tmp->next;
	}
	return (NULL);
}
