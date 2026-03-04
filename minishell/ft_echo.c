/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:33:25 by pukchayn          #+#    #+#             */
/*   Updated: 2026/03/01 17:06:38 by ferrarinara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool check_option_n(char *n)
{
	int i;

	i = 0;
	while (n[i] != '\0')
	{
		if (i == 0 && n[i] != '-')
			return (false);
		if (n[i] != 'n' && i != 0)
			return (false);
		i++;
	}
	return (true);
}

void ft_echo(t_user_input *user_input_table)
{
	t_user_input *tmp;
	bool newline;
	bool No_NewLine_Option;
	int i;

	tmp = user_input_table;
	i = 0;
	while (tmp != NULL)
	{
		if (i == 1 && check_option_n(tmp->str) == true)
		{
			No_NewLine_Option = true;
			newline = false;
		}
		else if (i != 0 && (No_NewLine_Option != true || check_option_n(tmp->str) != true))
		{
			No_NewLine_Option = false;
			printf("%s",tmp->str);
			if (tmp->next != NULL)
				printf(" ");
		}
		tmp = tmp->next;
		i++;
	}
	if (newline == true)
		printf("\n");
}
