/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vorhansa <vorhansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:34:39 by vorhansa          #+#    #+#             */
/*   Updated: 2025/09/09 14:29:47 by vorhansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_make_words(char *word, char const *s, int j, int word_ln)
{
	int	i;

	i = 0;
	while (word_ln > 0)
		word[i++] = s[j - word_ln--];
	word[i] = '\0';
	return (word);
}

static char	**ft_split_words(char **res, char const *s, char c, int word_cnt)
{
	int	i;
	int	j;
	int	word_ln;

	i = 0;
	j = 0;
	word_ln = 0;
	while (s[j] && i < word_cnt)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_ln++;
		}
		res[i] = (char *)malloc(sizeof(char) * (word_ln + 1));
		if (!res[i])
			return (NULL);
		ft_make_words(res[i], s, j, word_ln);
		word_ln = 0;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		word_cnt;
	char	**res;

	if (s == NULL)
		return (NULL);
	word_cnt = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	ft_split_words(res, s, c, word_cnt);
	return (res);
}

// int	main(void)
// {
// 	char	s1[] = "Words.to.be.splitted.in.six";
// 	char	s2;
// 	char	**words;
// 	int		i;

// 	s2 = '.';
// 	words = ft_split(s1, s2);
// 	i = 0;
// 	printf("Before: [%s]\nSplitter: [%c]\nAfter: \n", s1, s2);
// 	while (words[i])
// 	{
// 		printf("words[%d] : %s\n", i, words[i]);
// 		free(words[i]);
// 		i++;
// 	}
// 	printf("-------------------------------------------------\n");
// 	free(words);
// }