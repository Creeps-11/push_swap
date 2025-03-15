/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:21:15 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 00:07:54 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in(int nb, t_stack *index)
{
	int	i;

	i = -1;
	while (++i < *index->size)
		if (index->tab[i] == nb)
			return (i);
	return (-1);
}

int	in_chunk(int nb, t_stack *index, t_data *data, int chunk)
{
	int	i;
	int	limit;

	i = *data->chsize * chunk - 1;
	limit = (*data->chsize * chunk) + *data->chsize;
	if (chunk == *data->chunks * 2 - 1)
		limit = *index->size;
	while (++i < limit)
		if (index->tab[i] == nb)
			return (i);
	return (-1);
}

int	biggest_in(t_stack *s)
{
	int	i;
	int	nb;

	i = -1;
	nb = s->tab[0];
	while (++i < *s->size)
		if (nb < s->tab[i])
			nb = s->tab[i];
	return (nb);
}

int	left_in_a(t_stack *a, t_data *data, t_stack *index, int chunk)
{
	int	i;

	i = 0;
	while (i < *a->size)
	{
		if (in_chunk(a->tab[i], index, data, chunk) >= 0)
			return (i);
		i++;
	}
	return (-1);
}
