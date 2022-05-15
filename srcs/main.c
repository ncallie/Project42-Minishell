/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:36:16 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/05 16:34:49 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

void	init_structs(t_input *in)
{
	in->user_in = NULL;
	in->split_in = NULL;
	in->cmd_path = NULL;
	in->total_pipes = 0;
	in->fd_in = 0;
	in->fd_out = 0;
	in->status = 0;
	g_exit_status = 0;
}

void	update_level(t_input *in)
{
	int		level;
	char	*number;
	char	*aux;

	aux = ft_getenv("SHLVL", in);
	level = ft_atoi(aux);
	if (level < -1)
		level = -1;
	free(aux);
	level++;
	number = ft_itoa(level);
	update_env_var(in, "SHLVL=", number);
	free(number);
}

int	main(int argc, char **argv, char **environ)
{
	t_input	in;
	t_list	*envp;

	(void)argv;
	envp = NULL;
	if (argc == 1)
	{
		init_env_list(&in, &envp, environ);
		init_structs(&in);
		update_level(&in);
		while (1)
		{
			signal(SIGINT, handler);
			signal(SIGQUIT, SIG_IGN);
			in.status = 0;
			read_input(&in);
			unlink(".hd_tmp");
		}
	}
	return (0);
}
