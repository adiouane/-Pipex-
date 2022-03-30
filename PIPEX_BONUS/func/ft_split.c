/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:04:50 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/21 11:31:36 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	get_count(char const *s, char d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == d)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != d)
				i++;
		}
	}
	return (count);
}

static char	*ft_word_cpy(char *word, char const *s, int j, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		word[i] = s[j - word_len];
		word_len--;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **str, int wordlen)
{
	int	i;

	i = 0;
	while (i < wordlen)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static char	**ft_split2(char **str, char const *s, char c, int word_num)

{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < word_num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		str[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!str)
			return (ft_free(str, i));
		ft_word_cpy(str[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_num;

	if (!s)
		return (NULL);
	word_num = get_count(s, c);
	str = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!str)
		return (NULL);
	ft_split2(str, s, c, word_num);
	return (str);
}
