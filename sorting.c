/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:00:10 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 16:01:24 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < *s->size - 1)
	{
		if (s->tab[i] > s->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	bubblesort(t_stack *s)
{
	int	i;
	int	temp;

	while (!is_sorted(s))
	{
		i = 0;
		while (i < *s->size - 1)
		{
			if (s->tab[i] > s->tab[i + 1])
			{
				temp = s->tab[i];
				s->tab[i] = s->tab[i + 1];
				s->tab[i + 1] = temp;
			}
			i++;
		}
	}
}

int	freearray(char **s, int index)
{
	if (s)
		while (index--)
			free(s[index]);
	free(s);
	return (0);
}

int	count_args(char **args)
{
	int	i;

	i = 0;
	if (args)
		while (args[i] != NULL)
			i++;
	return (i);
}

int	is_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}
