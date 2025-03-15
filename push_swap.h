/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:26:37 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 15:20:16 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s
{
	int	*tab;
	int	*size;
}	t_stack;

typedef struct d
{
	int	*chunks;
	int	*chsize;
}	t_data;

int		freearray(char **s, int index);
int		count_args(char **args);
char	**split_args(int argc, char **argv);
int		is_atoi(const char *str);
int		check_list(char **args);
void	load_args(char **split_args, int *a);
t_stack	*init_stack(int calloc_size);
t_stack	*copy_stack(t_stack *model);
void	free_stack(t_stack *s);
t_data	*init_data(int tabsize, int nbchunks);
void	free_data(t_data *c);
void	bubblesort(t_stack *s);
int		is_sorted(t_stack *s);
int		is_in(int nb, t_stack *s);
int		biggest_in(t_stack *s);
int		in_chunk(int nb, t_stack *index, t_data *data, int chunk);
int		left_in_a(t_stack *a, t_data *data, t_stack *index, int chunk);
void	from_a_to_b(t_stack *a, t_stack *b, t_stack *idx, t_data *d);
void	from_b_to_a(t_stack *a, t_stack *b, t_stack *idx);
int		move(char *flag, t_stack *a, t_stack *b);
#endif