/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:49:22 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 03:44:21 by pukchayn         ###   ########.fr       */
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

t_env *table_link_env(char *str,char *str2, t_env *node)
{
	t_env *tmp;
	
	if (node == NULL)
	{
		node = new_node_env(str, str2);
		return (node);
	}
	tmp = node;
	while (tmp->next != NULL)	
		tmp = tmp->next;
	tmp->next = new_node_env(str, str2);
	return (node);
}
