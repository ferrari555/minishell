/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:10:47 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 16:11:21 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *export_name(char *str)
{
	int i;
	char *name;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	name = malloc((sizeof(char) * i) + 1);
	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char *export_object(char *str)
{
	int i;
	int x;
	int is_equel;
	char *object;
	
	i = 0;
	x = 0;
	is_equel = -1;
	while (str[i] != '\0')
	{
		i++;
		if (is_equel != -1)
			x++;
		if (str[i] == '=')
			is_equel = i++ + 1;
	}
	if (x == 0)
		return (NULL);
	object = malloc(x + 1);
	i = 0;
	while (str[is_equel] != '\0')
		object[i++] = str[is_equel++];
	object[i] = '\0';
	return (object);
}

void ft_export(t_user_main *user_input_table)
{
	char *name;
	char *object;
	t_user_input *tmp;

	tmp = user_input_table->user;
	if (tmp->next == NULL)
		return ;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		name = export_name(tmp->str);
		object = export_object(tmp->str);
		if (!user_input_table->env)
			user_input_table->env = table_link_env(name,object,NULL);
		else
			user_input_table->env = table_link_env(name,object,user_input_table->env);
		tmp = tmp->next;
	}
}
