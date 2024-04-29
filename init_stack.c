/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:36:52 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/28 16:37:01 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_stack **stack, int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = number;
	new_node->value_index = -1;
	new_node->stack_index = -1;
	new_node->how_far = 1000;
	new_node->top = NULL;
	new_node->rear = NULL;
	if (!*stack)
		(*stack) = new_node;
	else
	{
		new_node->rear = *stack;
		(*stack)->top = new_node;
		*stack = new_node;
	}
}

void	init_stack(t_stack **stacka, int *tab, int size)
{
	while (size >= 0)
	{
		create_node(stacka, tab[size]);
		size--;
	}
	repair_stack(stacka);
	sort_value_index(stacka);
}
