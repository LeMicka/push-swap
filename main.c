/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:54:13 by mbruzzi           #+#    #+#             */
/*   Updated: 2023/03/08 11:22:35 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void){
	system("leaks pushswap");
}

void	ft_free(t_var *variables)
{
	int	i;

	i = 0;
	if (variables->arg_type == 1)
	{
		while (variables->split[i])
		{
			free(variables->split[i]);
			i++;
		}
		free(variables->split);
		free (variables);
	}
	if (variables->arg_type == 0)
	{
		free(variables->split);
		free (variables);
	}
}

void	ft_free_list(t_bounds *stack)
{
	t_stack	*curent;

	while (stack->head != NULL)
	{
		curent = stack->head;
		stack->head = stack->head->next;
		free(curent);
	}
	free(stack);
}


int	main(int argc, char **argv)
{	
	t_var			*variables;
	t_bounds		*stack_a;
	t_bounds		*stack_b;
	int				i;
	t_stack			*curent;

	stack_a = NULL;
	stack_b = NULL;
	variables = NULL;
	stack_b = (t_bounds *)malloc(sizeof(t_bounds));
	variables = struct_init(variables);
	variables->split = fill_split(argc, argv);
	variables->arg_type = fill_arg_type(argc);
	i = 0;
	if (!variables || argc <= 1 || check_errors(variables->split) == 0)
	{
		ft_printf("error 1\n");
		ft_free(variables);
		return (0);
	}
	variables->len = array_length(variables->split);
	stack_a = create_list(variables->split, variables->len);
	sorting(variables, stack_a, stack_b);
	curent = stack_a->head;
	while (curent)
	{
		ft_printf("%i\n", curent->data);
		curent = curent->next;
	}
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	ft_free(variables);
	//atexit(ft_leaks);
	return (0);
}
