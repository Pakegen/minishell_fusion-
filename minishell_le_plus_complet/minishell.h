/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 03:45:08 by qacjl             #+#    #+#             */
/*   Updated: 2025/03/04 03:45:09 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_ARGS 64

# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <signal.h>
# include <sys/wait.h>
# include "libft/libft.h"

/* Structures et types */

typedef struct s_command
{
	char	**args;
	char	*heredoc_delim;
} t_command;

typedef struct s_pipeline
{
	t_command	*commands;
	int			count;
} t_pipeline;

typedef struct s_exec_context
{
	t_pipeline	*pipeline;
	char		**env;
	int			cmd_count;
} t_exec_context;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
} t_env;

typedef struct s_shell
{
	int		shlvl;
	char	*path;
	char	*home_path;
	char	*pwd;
	char	*old_pwd;
	char	**splitted_path;
	char	**env;
	t_list	*env_lines;
	t_list	*export_lines;
} t_shell;

typedef struct s_prompt
{
	char	*cmd_line;
	char	*echo;
	char	**strs;
	int		nb_args;
} t_prompt;

typedef enum e_state
{
	STATE_DEFAULT,
	STATE_IN_SINGLE,
	STATE_IN_DOUBLE,
	STATE_ESCAPING
} t_state;

typedef struct s_tokenize_context
{
	int		i;
	int		ti;
	char	**tokens;
	char	*curr;
	t_state	state;
} t_tokenize_context;

/* --- Tokenisation --- */
char	**advanced_tokenize(const char *line);
void	process_default(char c, t_state *state, char **curr);
void	process_in_single(char c, t_state *state, char **curr);
void	process_in_double(char c, t_state *state, char **curr);
void	process_escaping(char c, t_state *state, char **curr);

/* --- Parsing --- */
t_pipeline	*parse_input(const char *line);
void		free_pipeline(t_pipeline *pipeline);
void		parse_command_line(char *line, char **env);
int			is_valid(char *cmd_line);
int			count_strings(char **strs);
int			count_words(const char *str);
char		*find_third_word(const char *cmd_line);

/* --- Pipeline & Exécution --- */
void		execute_pipeline(t_pipeline *pipeline, char **env);
void		handle_pipe(char *cmd1[], char *cmd2[]);
int			redirect_file(const char *target, int std_fd, int flags, int mode);

/* --- Redirections --- */
int			adv_handle_redirect(const char *target, const char *op, int std_fd);
int			handle_redirection_char(const char *file, const char *op);
int			handle_heredoc(const char *delimiter);

/* --- Signaux --- */
void		setup_signal(void);
void		handle_sigint(int sig);
void		handle_sigquit(int sig);

/* --- Builtins --- */
void		exec_cd(t_shell *shell, t_prompt *prompt);
void		exec_export(t_shell *shell, t_prompt *prompt);
void		exec_unset(t_shell *shell, t_prompt *prompt);
void		exec_setenv(t_shell *shell, t_prompt *prompt);
void		exec_unsetenv(t_shell *shell, t_prompt *prompt);
void		exec_echo(t_prompt *prompt);
void		exec_exit(void);
void		execute_builtin(t_shell *shell, t_prompt *prompt);

/* --- Environment management --- */
char		*find_path_line(char **envp);
char		*get_path_value(char **envp, char *name);
char		*get_pwd(char **envp);
int			get_shell_level(char **envp);
char		**split_path(char **envp);
char		**split_path_from_value(const char *path_value);
void		copy_env(t_env **env, char **envp);
void		copy_export(t_env **export, char **envp);

/* --- Prompt & Utilitaires --- */
t_prompt	*init_prompt(const char *buffer);
char		*ft_strjoin2(int size, char **strs, char *sep);
char		*ft_strndup(const char *src, size_t n);
char		*replace(const char *str, char *a, char *b);
void		sort_strings(char **envp, int size);

#endif
