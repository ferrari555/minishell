/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:10:47 by pukchayn          #+#    #+#             */
/*   Updated: 2026/03/01 16:39:25 by ferrarinara      ###   ########.fr       */
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

int linklist_size(t_env *env)
{
	t_env *tmp;
	int i;

	i = 0;
	tmp = env;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int ft_strlen_env(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (2);
	else if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *env_str(t_env *env)
{
	t_env *tmp;
	char *str;
	int x;

	x = 0;
	tmp = env;
	str = malloc(ft_strlen(tmp->name) + ft_strlen_env(tmp->str) + 2);
	str = put_str(tmp->name,str,&x);
	str[x++] = '=';
	if (tmp->str == NULL)
	{
		str[x++] = '\'';
		str[x++] = '\'';
		str[x] = '\0';
		return (str);
	}
	str = put_str(tmp->str,str,&x);
	str[x] = '\0';
	return (str);
}

char **env_array(t_env *env)
{
	char **env_main;
	t_env *tmp;
	int size;
	int i;
	
	tmp = env;
	size = linklist_size(env);
	i = 0;
	env_main = malloc(sizeof(char *) * size + 1);
	while (tmp != NULL)
	{
		env_main[i] = env_str(tmp);
		tmp = tmp->next;
		i++;
	}
	env_main[i] = NULL;
	return (env_main);
}

void free_double_array(char **box)
{
	int i;

	i = 0;
	while (box[i] != NULL)
	{
		free(box[i]);
		i++;
	}
	free(box);
}

void print_export(t_env *env)
{
	char **env_box;
	int i;

	i = 0;
	env_box = env_array(env);
	env_box = bubble_sort(env_box);
	while (env_box[i] != NULL)
	{
		printf("%s\n", env_box[i]);
		i++;
	}
	free_double_array(env_box);
}

void ft_export(t_user_main *user_input_table)
{
	char *name;
	char *object;
	t_user_input *tmp;

	tmp = user_input_table->user;
	if (tmp->next == NULL)
		return (print_export(user_input_table->env));
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
