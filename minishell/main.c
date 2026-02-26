/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:30:36 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/26 19:13:04 by ferrarinara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool ft_strcmp_bool(char *str, char *str2)
{
	int i;
	
	i = 0;
	if (str == NULL || str[0] == '\0' || !str)
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] != str2[i] || str[i] == '\0' || str2[i] == '\0')
			return (false);
		i++;
	}
	return (true);
}

void test_print_list(t_user_main *user_input_table)
{
	t_env		*tmp2;

	tmp2 = user_input_table->env;
	// while (tmp != NULL)
	// {
	// 	printf("input: %s\n",tmp->str);
	// 	tmp = tmp->next;
	// }
	if (!tmp2)
		return ;
	while (tmp2 != NULL)
	{
		printf("name: %s\n",tmp2->name);
		printf("value: %s\n",tmp2->str);
		tmp2 = tmp2->next;
	}
}

void execute(t_user_main *user_input_table)
{
	if (ft_strcmp_bool(user_input_table->user->str,"echo") == true)
		ft_echo(user_input_table->user);
	else if (ft_strcmp_bool(user_input_table->user->str,"export") == true)
		ft_export(user_input_table);
}

void print_array(char **box)
{
	int i;
	
	i = 0;
	while (box[i] != NULL)
	{
		printf("%s\n",box[i]);
		i++;
	}
}

int main(int ac, char **ag, char **env)
{
	char *user_input;
	t_user_main *user_input_table;

	user_input_table = malloc(sizeof(t_user_main));
	user_input_table->env = ft_env(env);
	// print_array(env);
	// test_print_list(user_input_table);
	(void) ac;
	(void) ag;
	while (1)
	{
		user_input = readline(">> minishell: ");
		if (!user_input || user_input[0] == '\0')
			continue;
		user_input_table->user = passer(user_input,' ',user_input_table->env);
		if (user_input_table == NULL)
			free(user_input);
		if (ft_strcmp_bool(user_input_table->user->str,"exit") == true)
		{
			printf("exit\n");
			break;
		}
		init_type(user_input_table->user);
		execute(user_input_table);
		add_history(user_input);
		free_table_input(user_input_table->user);
		free(user_input);
	}
}
