/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:42:54 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/25 10:34:49 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ctrl_c(int plop)
{
	(void) plop;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	return ;
}

static void	nothing(void)
{
	return ;
}

static __sighandler_t	ctrl_backslash(void)
{
	nothing();
}

void	build_signal(void)
{
	signal(SIGQUIT, ctrl_backslash());
	signal(SIGINT, ctrl_c);
	rl_catch_signals = 0;
}
