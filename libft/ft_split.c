/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:54:46 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/07 12:02:14 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char d)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == d)
			str++;
		if (*str)
			count++;
		while (*str && *str != d)
			str++;
	}
	return (count);
}

static void	ft_free_split(char **ss)
{
	int	c;

	c = 0;
	while (ss[c] != NULL)
	{
		free(ss[c]);
		c++;
	}
	free(ss);
}

static int	ft_word_len(char *str, char d, int word)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	while (str[a] != '\0')
	{
		while (str[a] == d)
			a++;
		if (str[a] != '\0')
		{
			if (b == word)
			{
				c = 0;
				while (str[a + c] != d && str[a + c] != '\0')
					c++;
				return (c);
			}
			b++;
			while (str[a] != d && str[a] != '\0')
				a++;
		}
	}
	return (0);
}

static int	ft_start_index(char *s, char d, int word)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		while (s[a] == d)
			a++;
		if (s[a] != '\0')
		{
			if (b == word)
				return (a);
			b++;
			while (s[a] != d && s[a] != '\0')
				a++;
		}
	}
	return (a);
}

char	**ft_split(char const *s, char d)
{
	size_t	a;
	size_t	wordlen;
	char	**str;
	size_t	word_count;

	word_count = count_words(s, d);
	str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!str || !s)
		return (NULL);
	a = 0;
	while (a < word_count)
	{
		wordlen = ft_word_len((char *)s, d, a);
		str[a] = (char *)malloc(sizeof(char) * (wordlen + 1));
		if (str[a] == NULL)
		{
			ft_free_split(str);
			return (NULL);
		}
		ft_strlcpy(str[a], s + ft_start_index((char *)s, d, a), wordlen + 1);
		a++;
	}
	str[word_count] = NULL;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    int i;
    char *str = "hello. world. ola. adeus";
    char **result = ft_split(str, '.');
    
    if (result)
    {
        i = 0;
        while(result[i] != NULL)
        {
            printf("%s\n", result[i]);
            i++;
        }
        ft_free_split(result);
    }
    else
    {
        printf("Split failed\n");
    }
    return 0;
}*/
