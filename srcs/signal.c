/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:36:08 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/01 17:13:35 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler(int code)
{
	if (code == SIGINT)
	{
		g_exit_status = 1;
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler2(int code)
{
	if (code == SIGINT)
	{
		write(2, "\n", 1);
		g_exit_status = 130;
	}
	else if (code == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		g_exit_status = 131;
	}
}

void	handler4(int code)
{
	if (code == SIGINT)
	{
		write(2, "\n", 1);
		exit(250);
	}
}
