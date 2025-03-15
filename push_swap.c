/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:27:22 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/02/05 19:13:54 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack *a, t_stack *b)
{
	if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[0] < a->tab[2])
		return (move("sa", a, b), 1);
	else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[0] > a->tab[2])
		return (move("sa", a, b), move("rra", a, b), 1);
	else if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
		&& a->tab[0] > a->tab[2])
		return (move("ra", a, b), 1);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[0] < a->tab[2])
		return (move("sa", a, b), move("ra", a, b), 1);
	else if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
		&& a->tab[0] > a->tab[2])
		return (move("rra", a, b), 1);
	return (1);
}

int	sort_fourfive(t_stack *a, t_stack *b, t_stack *index)
{
	while (*a->size != 3)
		move("pb", a, b);
	sort_three(a, b);
	if (is_sorted(b))
		move("sb", a, b);
	if (b->tab[0] > biggest_in(a))
		move("pa", a, b);
	while (*b->size > 0)
	{
		if (is_in(a->tab[0], index) == is_in(b->tab[0], index) + 1)
			move("pa", a, b);
		else
			move("rra", a, b);
	}
	while (!is_sorted(a))
	{
		if (is_in(biggest_in(a), a) > (*a->size / 2) - 1)
			move("rra", a, b);
		else
			move("ra", a, b);
	}
	return (1);
}

int	sort(t_stack *a, t_stack *b, t_stack *index)
{
	t_data	*data;

	if (*a->size <= 50)
		data = init_data(*a->size, 5);
	else if (*a->size <= 100)
		data = init_data(*a->size, 10);
	else
		data = init_data(*a->size, 20);
	from_a_to_b(a, b, index, data);
	from_b_to_a(a, b, index);
	free_data(data);
	return (1);
}

int	push_swap(t_stack *a, t_stack *b)
{
	t_stack	*index_tab;

	index_tab = copy_stack(a);
	if (!index_tab)
		return (free_stack(index_tab), 1);
	bubblesort(index_tab);
	if (*a->size == 2)
		move("sa", a, b);
	else if (*a->size == 3)
		sort_three(a, b);
	else if (*a->size == 4 || *a->size == 5)
		sort_fourfive(a, b, index_tab);
	else if (*a->size > 5)
		sort(a, b, index_tab);
	return (free_stack(index_tab), 1);
}

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;

	args = split_args(argc, argv);
	if (args == 0)
		return (freearray(args, count_args(args)), write(2, "Error\n", 6), 0);
	a = init_stack(count_args(args));
	b = init_stack(count_args(args));
	if (!a || !b)
		return (write(2, "Error\n", 6), 0);
	if (check_list(args))
	{
		load_args(args, a->tab);
		*a->size = count_args(args);
		*b->size = 0;
		if (!is_sorted(a))
			push_swap(a, b);
	}
	else
		write(2, "Error\n", 6);
	return (free_stack(a), free_stack(b), freearray(args, count_args(args)), 0);
}
