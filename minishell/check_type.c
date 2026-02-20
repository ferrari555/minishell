/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:59:20 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 16:33:02 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_input_user_type return_command_type(char *str)
{
	if (ft_strcmp(str,"echo") == true)
		return (T_COMMAND);
	else if (ft_strcmp(str,"cd") == true)
		return (T_COMMAND);
	else if (ft_strcmp(str,"pwd") == true)
		return (T_COMMAND);
	else if (ft_strcmp(str,"export") == true)
		return (T_COMMAND);
	else if (ft_strcmp(str,"unset") == true)
		return (T_COMMAND);
	else if (ft_strcmp(str,"env") == true)
		return (T_COMMAND);
	else if (ft_strcmp(str,"exit") == true)
		return (T_COMMAND);
	return (T_NONE);
}

t_input_user_type return_redir_type(char *str)
{
	if (ft_strcmp(str,">") == true)
		return (T_REDIR);
	else if (ft_strcmp(str,"<") == true)
		return (T_REDIR);
	else if (ft_strcmp(str,"<<") == true)
		return (T_REDIR);
	else if (ft_strcmp(str,">>") == true)
		return (T_REDIR);
	return (T_NONE);
}

t_input_user_type return_other_type(char *str)
{
	if (ft_strcmp(str,"|") == true)
		return (T_PIPE);
	return (T_NONE);
}

t_input_user_type firstcase_input(char *str)
{
	if (return_command_type(str) != T_NONE)
		return (return_command_type(str));
	else if (return_redir_type(str) != T_NONE)
		return (return_redir_type(str));
	else if (return_other_type(str) != T_NONE)
		return (return_other_type(str));
	return T_STRING;
}

t_input_user_type othercase_input(char *str)
{
	if (return_redir_type(str) != T_NONE)
		return (return_redir_type(str));
	else if (return_other_type(str) != T_NONE)
		return (return_other_type(str));
	return T_STRING;
}

t_input_user_type return_type(char *str, int num)
{
	if (num == 0)
		return (firstcase_input(str));
	return (othercase_input(str));
}

t_user_input *init_type(t_user_input *user_input)
{
	t_user_input *tmp;
	int i;

	i = 0;
	tmp = user_input;
	while (tmp != NULL)
	{
		printf("text: %s\n",tmp->str);
		tmp->type = return_type(tmp->str, i);
		printf("%d\n", tmp->type);
		tmp = tmp->next;
		i = 1;
	}
	return (user_input);
}
