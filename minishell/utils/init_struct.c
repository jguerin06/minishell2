/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:55 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/24 17:21:49 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_shell(t_shell *shell)
{
	shell->all = NULL;
	shell->cmd = NULL;
	shell->p_cmd = NULL;
	shell->env = NULL;
	shell->forked_cmd = 0;
	shell->mini = 1;
	shell->argc = 0;
	shell->pipl.n_steps = 0;
	shell->status = 0;
	shell->redir = 0;
}
