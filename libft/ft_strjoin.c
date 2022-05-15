/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:26:40 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/16 13:32:47 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*conc;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	conc = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!conc)
		return (NULL);
	ft_strlcpy (conc, s1, s1_len + 1);
	ft_strlcat (conc + s1_len, s2, s2_len + 1);
	return (conc);
}
