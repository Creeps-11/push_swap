/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:54:25 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 00:11:11 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int calloc_size)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->tab = ft_calloc(sizeof(int), calloc_size);
	if (!s->tab)
		return (NULL);
	s->size = (int *) malloc(sizeof(int));
	if (!s->size)
		return (NULL);
	*s->size = 0;
	return (s);
}

void	free_stack(t_stack *s)
{
	free(s->tab);
	free(s->size);
	free(s);
}

t_stack	*copy_stack(t_stack *model)
{
	t_stack	*copy;
	int		i;

	copy = (t_stack *)malloc(sizeof(t_stack));
	if (!copy)
		return (NULL);
	copy->tab = ft_calloc(sizeof(int), *model->size);
	if (!copy->tab)
		return (NULL);
	i = 0;
	while (i < *model->size)
	{
		copy->tab[i] = model->tab[i];
		i++;
	}
	copy->size = (int *) malloc(sizeof(int));
	if (!copy->size)
		return (NULL);
	*copy->size = *model->size;
	return (copy);
}

t_data	*init_data(int tabsize, int nbchunks)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->chunks = (int *) malloc(sizeof(int));
	d->chsize = (int *) malloc(sizeof(int));
	if (!d || !d->chunks || !d->chsize)
		return (free(d), free(d->chunks), free(d->chsize), NULL);
	*d->chunks = nbchunks / 2;
	*d->chsize = tabsize / nbchunks;
	return (d);
}

void	free_data(t_data *d)
{
	free(d->chunks);
	free(d->chsize);
	free(d);
}
