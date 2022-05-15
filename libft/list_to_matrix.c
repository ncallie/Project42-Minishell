/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:39:47 by ncallie           #+#    #+#             */
/*   Updated: 2022/03/01 14:39:49 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**list_to_matrix(t_list *lst)
{
	int		i;
	char	**matrix;
	t_list	*aux;

	i = 0;
	aux = lst;
	matrix = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (aux)
	{
		matrix[i] = ft_strdup(aux->content);
		aux = aux->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
