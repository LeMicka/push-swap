/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:11 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/28 09:33:27 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "printf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_moves
{
	int		a_moves;
	int		b_moves;
	int		index;
}	t_moves;

/**
 * @brief create thestructure containing global variables
 * 
*/
typedef struct s_var
{
	char	**split;
	int		len;
	int		arg_type;
	int		parts;
	int		in_a;
	int		in_b;
}	t_var;

typedef struct s_bounds
{
	struct s_stack	*head;
	struct s_stack	*last;
}	t_bounds;

/**
 * @brief create the stack linked list, for a and b
 * 
 * @param argc 
 * @param argv 
 * @return int 
*/
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
	int				order;
}	t_stack;

int				check_errors(char **split);
int				are_ints(char **split);
int				are_dup(char **split);
int				null_arg(char **split);
int				number_too_big(char **split);

t_var			*struct_init(t_var *variables);
char			**fill_split(int argc, char **argv);
int				array_length(char **split);
int				fill_arg_type(int argc);

t_bounds		*create_list(char **split, int len);

t_moves			*fastest_to_move(t_var *vars, t_bounds *a, t_bounds *b);

t_moves			*init_moves(t_moves *fastest);
void			assign_new_vals(t_moves *fastest, t_moves *curent);
void			last_a_moves(t_bounds *stack_a);
int				smallest_biggerr(t_bounds *stack_a, t_stack *to_push);

void			sorting(t_var *variables, t_bounds *stack_a, t_bounds *stack_b);
void			sort_3(t_bounds *stack_a);
void			sort_5(t_bounds *stack_a, t_bounds *stack_b);

void			sort_bigs(t_var *vars, t_bounds *stack_a, t_bounds *stack_b);

void			make_sa(t_stack *stack_a);
void			make_sb(t_stack *stack_b);
void			make_ss(t_stack *stack_a, t_stack *stack_b);

void			make_pa(t_bounds *stack_a, t_bounds *stack_b);
void			make_pb(t_bounds *stack_a, t_bounds *stack_b);

void			make_ra(t_bounds *stack_a);
void			make_rb(t_bounds *stack_b);
void			make_rr(t_bounds *stack_a, t_bounds *stack_b);

void			make_rra(t_bounds *stack_a);
void			make_rrb(t_bounds *stack_b);
void			make_rrr(t_bounds *stack_a, t_bounds *stack_b);

#endif
