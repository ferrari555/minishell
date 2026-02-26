/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:49:22 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/26 22:07:02 by ferrarinara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_table_input(t_user_input *node)
{
	t_user_input	*tmp;

	while (node != NULL)
	{
		tmp = node->next;
		free(node->str);
		free(node);
		node = tmp;
	}
}

t_user_input *new_node_input(char *str)
{
	t_user_input *node;
	
	node = malloc(sizeof(t_user_input));
	node->str = str;
	node->next = NULL;
	return (node);
}

t_user_input *table_link_input(char *str, t_user_input *node)
{
	t_user_input *tmp;
	
	if (node == NULL)
	{
		node = new_node_input(str);
		return (node);
	}
	tmp = node;
	while (tmp->next != NULL)	
		tmp = tmp->next;
	tmp->next = new_node_input(str);
	return (node);
}

void	free_table_env(t_env *node)
{
	t_env	*tmp;

	while (node != NULL)
	{
		tmp = node->next;
		free(node->str);
		free(node);
		node = tmp;
	}
}

t_env *new_node_env(char *str,char *str2)
{
	t_env *node;
	
	node = malloc(sizeof(t_env));
	node->name = str;
	if (!str2 || str2 == NULL)
		node->str = NULL;
	else
		node->str = str2;
	node->next = NULL;
	return (node);
}

bool check_already_exists(char *name, t_env *node)
{
	t_env *tmp;

	tmp = node;
	if (node == NULL)
		return (false);
	while (tmp != NULL)	
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

t_env *replace_env(char *name,char *object, t_env *node)
{
	t_env *tmp;
	
	tmp = node;
	while (tmp != NULL)	
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			if (tmp->str != NULL)
				free(tmp->str);
			tmp->str = object;
			return (node);
		}
		tmp = tmp->next;
	}
	return (node);
}

t_env *table_link_env(char *name,char *object, t_env *node)
{
	t_env *tmp;
	
	tmp = node;
	if (node == NULL)
	{
		node = new_node_env(name, name);
		return (node);
	}
	if (check_already_exists(name, node) == true)
		return (replace_env(name, object, node));
	while (tmp->next != NULL)	
		tmp = tmp->next;
	tmp->next = new_node_env(name, object);
	return (node);
}
