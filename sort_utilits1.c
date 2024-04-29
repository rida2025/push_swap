/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilits1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:06 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/19 12:39:48 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_value_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	int		i;

	i = 0;
	tmp = *stack;
	tmp1 = tmp->rear;
	while (tmp)
	{
		i = 0;
		while (tmp1)
		{
			if (tmp->value > tmp1->value)
				i++;
			tmp1 = tmp1->rear;
		}
		tmp->value_index = i;
		tmp = tmp->rear;
		tmp1 = *stack;
	}
}

void	sort_stack_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->stack_index = i;
		i++;
		tmp = tmp->rear;
	}
}

void	sort_howfar(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;

	i = 0;
	j = (size / 2) * -1 + 1;
	if (size % 2 != 0)
		j = (size / 2 + 1) * -1 + 1;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->stack_index <= size / 2 || size == 1)
		{
			tmp->how_far = i;
			i++;
		}
		else
		{
			tmp->how_far = j;
			j++;
		}
		tmp = tmp->rear;
	}
}

void	repair_stack(t_stack **stack)
{
	int	size;

	size = stack_size(stack);
	sort_stack_index(stack);
	sort_howfar(stack, size);
}
