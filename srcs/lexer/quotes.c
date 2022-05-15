/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:36:42 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/05 17:48:47 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quotes_state(t_input *in, char *str)
{
	if (str[in->f.i] == '\"'
		&& !in->f.single_q && !in->f.double_q)
	{
		in->f.double_q = 1;
		return (1);
	}
	else if (str[in->f.i] == '\"'
		&& !in->f.single_q && in->f.double_q)
	{	
		in->f.double_q = 0;
		return (1);
	}
	else if (str[in->f.i] == '\''
		&& !in->f.single_q && !in->f.double_q)
	{
		in->f.single_q = 1;
		return (1);
	}
	else if (str[in->f.i] == '\''
		&& in->f.single_q && !in->f.double_q)
	{
		in->f.single_q = 0;
		return (1);
	}
	return (0);
}

static void	delete_quote_aux(t_input *in, char *final_str, char *str)
{
	int	flag;

	flag = 0;
	ft_bzero(&in->f, sizeof(in->f));
	while (str[in->f.i])
	{
		if (!quotes_state(in, str))
		{
			if (str[in->f.i] == '\\' && ((str[in->f.i + 1] == '\'')
					|| (str[in->f.i + 1] == '\"')))
				flag = 1;
			else
				final_str[in->f.j++] = str[in->f.i];
		}
		if (flag == 1 && str[in->f.i] != '\\')
		{
			final_str[in->f.j++] = str[in->f.i];
			flag = 0;
		}
		in->f.i++;
	}
}

static char	*delete_quote(t_input *in, char *str)
{
	char	*final_str;
	int		flag;

	flag = 0;
	while (str[in->f.i])
	{
		if (!quotes_state(in, str))
		{
			if (str[in->f.i] == '\\' && ((str[in->f.i + 1] == '\'')
					|| (str[in->f.i + 1] == '\"')))
				flag = 1;
			else
				in->f.j++;
		}
		if (flag == 1 && str[in->f.i] != '\\')
		{
			in->f.j++;
			flag = 0;
		}
		in->f.i++;
	}
	final_str = malloc(sizeof(char) * (in->f.j + 1));
	final_str[in->f.j] = '\0';
	delete_quote_aux(in, final_str, str);
	return (final_str);
}

void	update_env_var(t_input *in, char *var, char *value)
{
	char	**aux_in;
	char	*tmp;

	aux_in = NULL;
	if (in->split_in)
		aux_in = matrix_dup(in->split_in);
	tmp = ft_strjoin(var, value);
	if (in->split_in)
		free_matrix(in->split_in);
	in->split_in = malloc(sizeof(char *) * 3);
	in->split_in[0] = ft_strdup("export");
	in->split_in[1] = tmp;
	in->split_in[2] = NULL;
	export(in);
	free_matrix(in->split_in);
	in->split_in = NULL;
	in->split_in = aux_in;
}

char	**quotes(t_input *in)
{
	int		size;
	int		i;
	char	*aux;

	i = 0;
	while (in->split_in[i] != NULL)
	{
		ft_bzero(&in->f, sizeof(in->f));
		aux = delete_quote(in, in->split_in[i]);
		if (!ft_strncmp(in->split_in[i], aux, ft_strlen(aux)))
			in->q_state[i] = 0;
		else
			in->q_state[i] = 1;
		free(in->split_in[i]);
		in->split_in[i] = aux;
		i++;
	}
	size = matrix_len(in->split_in);
	update_env_var(in, "_=", in->split_in[size - 1]);
	return (in->split_in);
}
