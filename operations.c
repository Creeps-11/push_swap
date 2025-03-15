/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:04:35 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/14 17:06:16 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s(t_stack *stack)
{
	int	temp;

	if (*stack->size > 1)
	{
		temp = stack->tab[0];
		stack->tab[0] = stack->tab[1];
		stack->tab[1] = temp;
	}
}

static void	r(t_stack *stack)
{
	int	temp;
	int	i;

	if (*stack->size > 1)
	{
		temp = stack->tab[0];
		i = 1;
		while (i < *stack->size)
		{
			stack->tab[i - 1] = stack->tab[i];
			i++;
		}
		stack->tab[i - 1] = temp;
	}
}

static void	rr(t_stack *stack)
{
	int	temp;
	int	i;

	if (*stack->size > 1)
	{
		temp = stack->tab[*stack->size - 1];
		i = *stack->size - 2;
		while (i >= 0)
		{
			stack->tab[i + 1] = stack->tab[i];
			i--;
		}
		stack->tab[0] = temp;
	}
}

static void	p(t_stack *src, t_stack *dest)
{
	int	temp;

	if (*src->size > 0)
	{
		temp = src->tab[0];
		r(src);
		*(src->size) -= 1;
		*(dest->size) += 1;
		rr(dest);
		dest->tab[0] = temp;
	}
}

int	move(char *flag, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(flag, "sa", 3))
		return (ft_printf("sa\n"), s(a), 1);
	if (!ft_strncmp(flag, "sb", 3))
		return (ft_printf("sb\n"), s(b), 1);
	else if (!ft_strncmp(flag, "ss", 3))
		return (ft_printf("ss\n"), s(a), s(b), 1);
	else if (!ft_strncmp(flag, "pa", 3))
		return (ft_printf("pa\n"), p(b, a), 1);
	else if (!ft_strncmp(flag, "pb", 3))
		return (ft_printf("pb\n"), p(a, b), 1);
	else if (!ft_strncmp(flag, "ra", 3))
		return (ft_printf("ra\n"), r(a), 1);
	else if (!ft_strncmp(flag, "rb", 3))
		return (ft_printf("rb\n"), r(b), 1);
	else if (!ft_strncmp(flag, "rr", 3))
		return (ft_printf("rr\n"), r(a), r(b), 1);
	else if (!ft_strncmp(flag, "rra", 3))
		return (ft_printf("rra\n"), rr(a), 1);
	else if (!ft_strncmp(flag, "rrb", 3))
		return (ft_printf("rrb\n"), rr(b), 1);
	else if (!ft_strncmp(flag, "rrr", 3))
		return (ft_printf("rrr\n"), rr(a), rr(b), 1);
	return (1);
}
