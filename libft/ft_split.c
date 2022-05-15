/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:27:56 by ncallie           #+#    #+#             */
/*   Updated: 2021/10/16 14:10:04 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_malloc(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	word_num;

	i = 0;
	word_num = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_num++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_num);
}

static char	*ft_word_make(char *word, char const *s, int k, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		word[i] = s[k - word_len];
		i++;
		word_len--;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_word_len(char **result, char const *s, char c, int word_num)
{
	int	word_len;
	int	k;
	int	i;

	word_len = 0;
	i = 0;
	k = 0;
	while (s[k] && i < word_num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (ft_free_malloc(result));
		ft_word_make (result[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**result;

	if (s == 0)
		return (NULL);
	word_num = ft_word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (NULL);
	ft_word_len (result, s, c, word_num);
	return (result);
}
