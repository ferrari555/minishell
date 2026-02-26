/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferrarinarangsiya <ferrarinarangsiya@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:33:25 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/26 00:57:30 by ferrarinara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_option_n(char *n);

void ft_echo(t_user_input *user_input_table)
{
	t_user_input *tmp;
	bool newline;
	int i;

	tmp = user_input_table;
	newline = true;
	i = 0;
	while (tmp != NULL)
	{
		if (i == 1 && ft_strcmp_bool(tmp->str,"-n") == true)
		{
			newline = false;
			tmp = tmp->next;
			continue;
		}
		if (i != 0)
			printf("%s",tmp->str);
		if (tmp->next != NULL)
			printf(" ");
		tmp = tmp->next;
		i++;
	}
	if (newline == true)
		printf("\n");
}
