/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:37:26 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/01 15:08:37 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv_aux(t_list *aux, char **var)
{
	int	total_size;
	int	size_var;

	size_var = ft_strlen(*var);
	while (aux)
	{
		total_size = ft_strlen(aux->content);
		if (!(ft_strncmp(*var, aux->content, size_var)))
		{
			free(*var);
			return (ft_substr(aux->content, size_var, total_size - size_var));
		}
		aux = aux->next;
	}
	free(*var);
	return (NULL);
}

char	*ft_getenv(const char *str, t_input *in)
{
	t_list	*aux;
	char	*var;

	aux = *in->env_list;
	var = NULL;
	var = ft_strjoin(str, "=");
	return (ft_getenv_aux(aux, &var));
}

void	dup_env(t_input *in, char **environ)
{
	int		i;

	i = 0;
	in->dup_env = NULL;
	if (!(*environ))
		;
	else
	{
		while (environ[i] != NULL)
			i++;
		in->dup_env = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (environ[i])
		{
			in->dup_env[i] = ft_strdup(environ[i]);
			i++;
		}
		in->dup_env[i] = NULL;
	}
}

void	init_env_list(t_input *in, t_list **envp, char **environ)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	dup_env(in, environ);
	while (in->dup_env[i] != NULL)
	{
		size = ft_strlen(in->dup_env[i]);
		ft_lstadd_back(envp, ft_new_node((void *) in->dup_env[i], size + 1));
		i++;
	}
	in->env_list = envp;
}
