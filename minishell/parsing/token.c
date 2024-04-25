/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguerin <jguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:31:43 by mbouaza           #+#    #+#             */
/*   Updated: 2024/04/25 08:16:01 by jguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	tokenizer(char *token)
{
	if (ft_strcmp(token, "|"))
		return (1);
	else if (ft_strcmp(token, "||"))
		return (2);
	else if (ft_strcmp(token, "&&"))
		return (3);
	else if (ft_strcmp(token, ">"))
		return (4);
	else if (ft_strcmp(token, ">>"))
		return (5);
	else if (ft_strcmp(token, "<"))
		return (6);
	else if (ft_strcmp(token, "<<"))
		return (7);
	return (0);
}
