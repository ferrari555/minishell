/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:03:34 by pukchayn          #+#    #+#             */
/*   Updated: 2026/02/20 17:57:06 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



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
