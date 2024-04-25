/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:59 by jguerin           #+#    #+#             */
/*   Updated: 2024/04/24 17:01:56 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	char_ccmp(char *str, char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (reject[j])
		{
			if (str[i] == reject[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_env_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static char	**ft_add_env(char **env)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (ft_env_len(env) + 2));
	while (env[i])
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

static int	ft_format_check(char *arg, t_shell *shell)
{
	int	current;
	int	flag;

	current = 0;
	flag = 0;
	while (arg[current] && arg[current] != '=')
	{
		if (!ft_isalpha(arg[current]) || is_d(arg[current]))
			flag = 1;
		current++;
	}
	if (flag == 0 && char_ccmp(arg, "=") == 1)
		return (0);
	else if (flag == 1)
		return (1);
}

void	ft_unset(char **cmd, char **argv, t_shell *shell)
{
	char	**cpy;
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 1;
	flag = 0;
	if (shell->argc == 1)
		return ;
	while (cmd[j])
	{
		i = ft_checkenv2(cmd[j], shell->env);
		if (i >= 0 && ft_format_check(cmd[j], shell) == 0)
		{
			free(shell->env[i]);
			cpy = ft_tabdup(shell->env);
			shell->env = ft_add_env(cpy);
			tab_free(cpy);
			shell->status = 0;
		}
		j++;
	}
}
