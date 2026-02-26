#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <stdbool.h>

typedef enum input_user_type
{
	T_NONE,
	T_STRING,
	T_PIPE,
	T_COMMAND,
	T_REDIR
} t_input_user_type;

typedef enum string_type
{
	T_DOUBLE_QUOTE,
	T_SINGLE_QUOTE
} t_string_type;

typedef struct s_env
{
	char		*name;
	char		*str;
	struct s_env *next;
} t_env;

typedef struct s_export_inpit
{
	char		*name;
	char		*str;
	struct s_export_inpit *next;
} t_export_inpit;

typedef struct s_user_input
{
	char                *str;
	t_input_user_type   type;
	struct s_user_input	*next;
} t_user_input;

typedef struct s_user_main
{
	t_user_input 	*user;
	t_env			*env;
} t_user_main;

t_user_input *table_link_input(char *str, t_user_input *node);
t_user_input *new_node_input(char *str);
t_env *new_node_env(char *str,char *str2);
t_env *table_link_env(char *name,char *object, t_env *node);

void	free_table_env(t_env *node);
void	free_table_input(t_user_input *node);

char	**ft_split(char const *s, char c);
t_user_input	*passer(char const *s, char c, t_env *env);
t_user_input *init_type(t_user_input *user_input);
bool ft_strcmp_bool(char *str, char *str2);
char *put_str_remove_quote(char *str, char c, t_env *env);
int count_char(char *str, char c);
size_t	len_str(char *s, char c);
char *find_env(t_env *env, char *str);
int len_split(char *str);
void ft_echo(t_user_input *user_input_table);
int ft_strlen(char *str);

char *export_name(char *str);
char *export_object(char *str);
void ft_export(t_user_main *user_input_table);
t_env *ft_env(char **env);
char **bubble_sort(char **env);
int ft_strcmp(char *str, char *str2);
char *put_str(char *str, char *str2, int *x);

#endif