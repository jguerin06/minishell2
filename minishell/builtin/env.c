/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:50:38 by jguerin           #+#    #+#             */
/*   Updated: 2024/01/31 14:45:49 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env(char **env, char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (cmd[j])
	{
		if (ft_strcmp(cmd[j], "env") != 0)
		{
			ft_putstr_fd("No such file or directory\n", 2);
			return ;
		}
		j++;
	}
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
