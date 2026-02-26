/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:03:34 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/26 01:41:17 by ferrarinara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strcmp(char *str, char *str2)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str2[i] != '\0')
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i++;
	}
	return (ft_strlen(str) - ft_strlen(str2));
}

bool check_if_sort(char **env)
{
	int i;

	i = 0;
	while (env[i + 1] != NULL)
	{
		if (ft_strcmp(export_name(env[i]),export_name(env[i + 1])) > 0)
			return (false);
	   	i++;
	}
	return (true);
}

char **bubble_sort(char **env)
{
	int i;
	char *box1;

	while (check_if_sort(env) != true)
	{
		i = 0;
		while (env[i + 1] != NULL)
		{
			if (ft_strcmp(export_name(env[i]),export_name(env[i + 1])) > 0)
			{
				box1 = env[i];
                env[i] = env[i + 1];
                env[i + 1] = box1;
			}
			i++;
		}
	}
	return (env);
}

t_env *ft_env(char **env)
{
	int i;
	char *name;
	char *value;
	t_env *env_link;

	i = 0;
	env_link = NULL;
	while (env[i] != NULL)
	{
		name = export_name(env[i]);
		value = export_object(env[i]);
		if (env_link == NULL)
			env_link = table_link_env(name,value,NULL);
		else
			env_link = table_link_env(name,value,env_link);
		i++;
	}
	return (env_link);
}

// int main(int ac,char **ag,char **env)
// {
// 	int i;

// 	(void) ac;
// 	(void) ag;
// 	char **env2 = bubble_sort(env);
// 	i = 0;
// 	while (env2[i] != NULL)
// 	{
// 		printf("%s\n",env2[i]);
// 		i++;
// 	}
// 	return (0);
// }