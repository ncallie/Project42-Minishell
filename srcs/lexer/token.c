/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:36:48 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/01 15:11:34 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	char_sp(char c)
{
	if (c != '\t' && c != ' ' && c != '\n'
		&& c != '\f' && c != '\v' && c != '\r')
		return (0);
	return (1);
}

void	count_tokens(char *s, t_input *in, int flag)
{
	while (s[in->f.i] != '\0')
	{
		quotes_state(in, s);
		if (char_sp(s[in->f.i]) && !flag)
			while (char_sp(s[in->f.i]) && s[in->f.i])
				in->f.i++;
		flag = 1;
		if (char_sp(s[in->f.i]) && !in->f.single_q && !in->f.double_q)
		{
			in->f.count++;
			while (char_sp(s[in->f.i]) && s[in->f.i])
				in->f.i++;
		}
		else if (s[in->f.i] != '\0')
		{
			in->f.i++;
			if (s[in->f.i] == '\0')
				in->f.count++;
		}
	}
}

void	split_tokens_aux(t_input *in, char *s)
{
	if (char_sp(s[in->f.i]) && !in->f.single_q && !in->f.double_q)
	{
		in->split_in[in->f.j]
			= ft_substr(s, in->f.start, in->f.i - in->f.start);
		in->f.j++;
		while (char_sp(s[in->f.i]) && s[in->f.i])
			in->f.i++;
		in->f.start = in->f.i;
	}
	else if (s[in->f.i] != '\0')
	{
		in->f.i++;
		if (s[in->f.i] == '\0')
		{
			in->split_in[in->f.j]
				= ft_substr(s, in->f.start, in->f.i - in->f.start);
		}
	}
}

void	split_tokens(char *s, t_input *in, int flag)
{
	in->f.i = 0;
	in->f.start = 0;
	while (s[in->f.i] != '\0')
	{
		quotes_state(in, s);
		if (char_sp(s[in->f.i]) && !flag)
		{
			while (char_sp(s[in->f.i]) && s[in->f.i])
				in->f.i++;
			in->f.start = in->f.i;
		}
		flag = 1;
		split_tokens_aux(in, s);
	}
}
