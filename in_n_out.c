/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_n_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:42:06 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 00:08:34 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rot_below(t_stack *a, t_stack *b, int nb, int biggest)
{
	if (biggest >= biggest_in(a) && biggest >= biggest_in(b))
	{
		if (b->tab[0] > a->tab[*a->size - 1])
			return (1);
	}
	else
	{
		if (nb < a->tab[0])
		{
			if (a->tab[*a->size - 1] == biggest_in(a))
				return (1);
			else
				if (nb > a->tab[*a->size - 1])
					return (1);
		}
	}
	return (0);
}

void	from_a_to_b(t_stack *a, t_stack *b, t_stack *idx, t_data *d)
{
	int		ctop;
	int		cbot;

	ctop = 0;
	cbot = 0;
	while (*a->size > 0)
	{
		if ((cbot < *d->chunks
				&& in_chunk(a->tab[0], idx, d, *d->chunks + cbot) >= 0)
			|| (ctop < *d->chunks
				&& in_chunk(a->tab[0], idx, d, *d->chunks - ctop - 1) >= 0))
		{
			move("pb", a, b);
			if (ctop < *d->chunks
				&& in_chunk(b->tab[0], idx, d, *d->chunks - ctop - 1) >= 0)
				move("rb", a, b);
		}
		else
			move("ra", a, b);
		if (cbot < *d->chunks && left_in_a(a, d, idx, *d->chunks + cbot) < 0)
			cbot++;
		if (ctop < *d->chunks
			&& left_in_a(a, d, idx, *d->chunks - ctop - 1) < 0)
			ctop++;
	}
}

void	from_b_to_a(t_stack *a, t_stack *b, t_stack *idx)
{
	int	big;

	while (*b->size > 0 || !is_sorted(a))
	{
		big = biggest_in(b);
		if (*a->size > 1
			&& is_in(a->tab[*a->size - 1], idx) == is_in(a->tab[0], idx) - 1)
			move("rra", a, b);
		else if (*b->size > 0 && (*a->size == 0 || b->tab[0] == big))
			move("pa", a, b);
		else if (*b->size > 0 && rot_below(a, b, b->tab[0], big))
		{
			move("pa", a, b);
			move("ra", a, b);
		}
		else if (*b->size > 0)
		{
			if (is_in(big, b) < (*b->size / 2) + 1)
				move("rb", a, b);
			else
				move("rrb", a, b);
		}
	}
}
