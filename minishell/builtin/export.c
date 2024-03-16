/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:51 by jguerin           #+#    #+#             */
/*   Updated: 2024/03/16 14:38:19 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


/*
Return error if :
- arg start with a number
- arg doesnt contain a letter or a number
- arg doesnt contain an equal sign
*/
/*
int	format_check(char *arg)
{
	int current;
	int has_equal;
	
	current = 0;
	has_equal = 0;
	if (!ft_isalpha(arg[0]))
		printf("Pas de lettre :(\n");
	while(arg[current])
	{
		if (arg[current] == '=')
			has_equal = 1;
		else if (!ft_isalnum(arg[current]) && arg[current] != '_')
			if (!has_equal)
				printf("");
	}
}
*/

/*
	Parse the current string (an arg) and add it to shell->env
	Return 0 on malloc error
	Return 1 on succeed
	Return 2 on command error (bad syntax, etc.)
*/

static int	env_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_export(char **cmd, char **argv, t_shell *shell)
{
	int i = 0;
	int j = 1;

	// sort_env(shell->env, env_len(shell->env));
	i = ft_checkenv(cmd[j], shell->env);
	printf("%d\n", i);
	if (i >= 0)
	{
		//printf("%s\n", shell->env[i]);
		free(shell->env[i]);
		shell->env[i] = ft_strdup(cmd[j]);
		//printf("%s\n", shell->env[i]);

	}

}

