/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:22:01 by jguerin           #+#    #+#             */
/*   Updated: 2024/04/25 09:19:31 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// --- [ include ] --- //

# include "../get_next_line/get_next_line.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// --- [ define ] --- //

// --- [ structure ] --- //

typedef struct Pipe
{
	int		n_steps;
}			t_pipe;

typedef struct shell
{
	int		mini;
	int		status;
	int		redir;
	int		argc;
	int		forked_cmd;
	char	*path;
	char	**all;
	char	**p_cmd;
	char	**cmd;
	char	**env;
	t_pipe	pipl;

}			t_shell;

typedef struct xt
{
	int		i;
	int		j;
	int		k;
}			t_exit;

// --- [ function ] --- //

void		print_tab(char **tab);

/* builtins */

void		env(char **env, char **cmd);

int			echo(char **args);

void		pwd(void);

void		ft_exit(char **argv, t_shell *shell, t_exit xt);

int			ft_cd(char **argv, t_shell *shell);

void		ft_export(char **cmd, char **argv, t_shell *shell);

void		ft_unset(char **cmd, char **argv, t_shell *shell);

/* launch */

void		launch(t_shell *shell);

/* parsing */

int			tokenizer(char *token);

int			update(char c, int *in_q);

void		parse(char *readed, t_shell *shell);

void		change_nl(char *readed);
char		*reboot_line(char *readed);

char		*wildcard(char *readed);

char		*quoted_line(char *line);
int			check_quote(char *s);

char		*rebuild_space_line(char *readed, int j, int in_q);

char		**cut_cmd(char *line);

void		find_bull(t_shell *shell, char **cmd, int i);
int			isnt_bull(t_shell *shell, char **cmd, int i);

/* exec */

void		shell_execve(char *e_cmd, char **env, t_shell *shell);
void		execute_pipeline(t_shell *shell, int i, int j, int input_fd);

void		redir(t_shell *shell, char **cmds);

/* history */

void		make_history(t_shell *shell);
void		history(char *readed);

/* utils */

int			quotes_cmd_size(char *line);

char		*actual_path(void);

void		init_shell(t_shell *shell);

/*utils free */

void		tab_free(char **tab);
void		global_free(t_shell *shell);

/* utils print */

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		put_error(char *exe, char *file, int err, char *error);

/* utils copy */

char		*ft_strdup(char *s1);
char		**ft_tabdup(char **tab);

/*utils basic */

int			ft_strcmp(char *s1, char *s2);
int			ft_atoi(char *str);
char		*ft_join(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

/* utils env */

int			ft_checkenv(char *str, char **env);
int			ft_checkenv2(char *str, char **env);
char		*ft_getenv(char *str, char **env);
void		sort_env(char **tab, int env_len);

/* utils check */

int			basic(int argc, char **env, t_shell *shell);
int			char_cmp(char *str, char *reject);
int			nb_arg(char **arg);
int			is_flag_valid(char *str);
int			is_d(int n);
int			str_is_num(char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
void		is_neg(int n, t_shell *shell);

/* signal */

void		build_signal(void);

/* status */

void		set_status(int set, t_shell *shell);

#endif
