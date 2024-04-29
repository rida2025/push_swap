/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:10 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/19 13:02:34 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_and_sendit(t_stack **stackA, t_stack **stackB)
{
	t_stack	*tmp;

	tmp = *stackA;
	while (tmp)
	{
		if (tmp->value_index == 0)
			break ;
		tmp = tmp->rear;
	}
	while (tmp->how_far != 0)
	{
		if (tmp->how_far >= 0)
			stack_ra(stackA, 0);
		else
			stack_rra(stackA, 0);
	}
	stack_pb(stackA, stackB, 0);
	sort_value_index(stackA);
}

void	sort_5(t_stack **stackA, t_stack **stackB, int size)
{
	if (size == 4)
	{
		find_min_and_sendit(stackA, stackB);
		sort_3(stackA);
		stack_pa(stackA, stackB, 0);
	}
	else
	{
		find_min_and_sendit(stackA, stackB);
		find_min_and_sendit(stackA, stackB);
		sort_3(stackA);
		sort_value_index(stackA);
		stack_pa(stackA, stackB, 0);
		sort_value_index(stackA);
		stack_pa(stackA, stackB, 0);
		sort_value_index(stackA);
	}
}
