/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:35:22 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 16:30:35 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL || !str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int count_char(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

bool swap_true_and_false(bool n, int *i)
{
	(*i)--;
	if (n == false)
		return (true);
	return (false);
}

int len_split(char *str)
{
	int i;

	i = 0;
	if (str == NULL || !str)
		return (0);
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
		i++;
	return (i);
}

int str_quote_size(char *str, char **env)
{
	int i;
	int len;
	bool single_quote;
	bool double_quote;

	i = 0;
	single_quote = false;
	double_quote = false;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && double_quote == false)
			single_quote = swap_true_and_false(single_quote, &len);
		else if (str[i] == '"' && single_quote == false)
			double_quote = swap_true_and_false(single_quote, &len);
		else if (str[i] == '$' && single_quote != true)
			len += ft_strlen(find_env(env,&str[++i]));
		i++;
	}
	return (len);
}

char *put_str(char *str, char *str2, int *x)
{
	int i;
	
	i = 0;
	if (str == NULL)
		return (str2);
	while (str[i] != '\0')
	{
		str2[*x] = str[i];
		(*x)++;
		i++;
	}
	return (str2);
}

char *put_str_remove_quote(char *str, char c, char **env)
{
	char *new_str;
	size_t i;
	int x;
	bool single_quote;
	bool double_quote;

	i = 0;
	x = 0;
	single_quote = false;
	double_quote = false;
	new_str = malloc(sizeof(char) * str_quote_size(str, env) + 1);
	if (!new_str)
		return (NULL);
	while (i <= len_str(str, c))
	{
		if (str[i] == '\'' && double_quote == false)
			single_quote = !single_quote;
		else if(str[i] == '"' && single_quote == false)
			double_quote = !double_quote;
		else if (str[i] == '$' && single_quote != true)
		{
			new_str = put_str(find_env(env,&str[++i]),new_str,&x);
			i += len_split(&str[i]) - 1;
		}
		else
			new_str[x++] = str[i];
		i++;
	}
	new_str[x] = '\0';
	return (new_str);
}

// int main(int ac,char **ag,char **env)
// {
// 	printf("%s\n",ag[ac - 1]);
// 	printf("%s\n",put_str_remove_quote("\"hello world\"",' ',env));
// }