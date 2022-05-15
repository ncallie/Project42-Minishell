/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:40:11 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/11 16:56:28 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_p;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	s_p = (char *)malloc(sizeof(char) * (len + 1));
	if (s_p == NULL)
		return (NULL);
	while (s[i])
	{
		s_p[i] = s[i];
		i++;
	}
	s_p[i] = '\0';
	return (s_p);
}
