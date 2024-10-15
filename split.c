/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuliki <chuliki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:47:38 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/15 17:16:54 by chuliki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char *s, char c)
{
	int		n;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

static int	ft_word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

static void	ft_free(char **s, int len)
{
	while (len >= 0)
		free(s[len]);
	free(s);
}

static void	ft_save_word(char **tab, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		if (*s && *s == c)
			s++;
		else
		{
			tab[i] = malloc(sizeof(char) * ft_word_len(s, c) + 1);
			if (!(tab[i]))
			{
				ft_free(tab, i - 1);
				return ;
			}
			j = 0;
			while (*s && *s != c)
				tab[i][j++] = *s++;
			i++;
		}
	}
}

char	**ft_split(char *str, char c)
{
	char	**tab;
	int		words;

	if (!str)
		return ((void *) NULL);
	words = ft_count_words(str, c);
	tab = malloc(sizeof(char *) * words + 1);
	if (!tab)
		return ((void *) NULL);
	tab[words] = 0x0;
	ft_save_word(tab, str, c);
	return (tab);
}
/*
int main (void)
{
	char **s = ft_split("Imagina tener un asistente de escritura muy inteligente que te ayude a crear todo tipo de texto, desde correos electrónicos y publicaciones en redes sociales hasta artículos e historias. ¡Eso es exactamente lo que hace un Generador de texto IA! ", ' ');
	int i = 0;
	while (s[i] != 0)
		printf("String:%s\n", s[i++]);
	return (0);
}
*/