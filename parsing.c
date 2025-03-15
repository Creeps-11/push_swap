/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:04:30 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 15:22:38 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**multiple_args(int argc, char **argv)
{
	char	**args_list;
	int		i;

	args_list = (char **)malloc((sizeof(char *) * argc));
	if (!args_list)
		return (NULL);
	i = 0;
	while (i != argc - 1)
	{
		args_list[i] = ft_strdup(argv[i + 1]);
		if (!args_list[i])
			return (NULL);
		i++;
	}
	args_list[i] = NULL;
	return (args_list);
}

char	**split_args(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else if (argc > 2)
		args = multiple_args(argc, argv);
	else
		return (0);
	if (!args)
		return (0);
	return (args);
}

static int	check_doubles(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i + 1] != NULL)
	{
		j = i + 1;
		while (args[j] != NULL)
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_list(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = 0;
		if (ft_atol(args[i]) > 2147483647 || ft_atol(args[i]) < -2147483648)
			return (0);
		while (args[i][j] != '\0')
		{
			if (!is_atoi(args[i]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_doubles(args))
		return (0);
	return (i);
}

void	load_args(char **split_args, int *a)
{
	int	i;

	i = 0;
	while (split_args[i] != NULL)
	{
		a[i] = ft_atoi(split_args[i]);
		i++;
	}
}
