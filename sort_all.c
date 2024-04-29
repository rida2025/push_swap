/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:03 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 09:46:10 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_chunk2(t_stack **stacka, t_stack **stackb, int chunk, int count)
{
	while (count > 0)
	{
		if (!*stacka)
			return ;
		if ((*stacka)->value_index >= chunk && \
		(*stacka)->value_index <= (chunk + 49))
		{
			if ((*stacka)->value_index > (chunk + 24))
				stack_pb(stacka, stackb, 0);
			else
			{
				stack_pb(stacka, stackb, 0);
				if (*stacka && !((*stacka)->value_index >= chunk && \
				(*stacka)->value_index <= (chunk + 49)))
					stack_rr(stacka, stackb, 0);
				else
					stack_rb(stackb, 0);
			}
			count--;
		}
		else
			stack_ra(stacka, 0);
	}
}

t_stack	*send_big_number2(t_stack **stack, int num)
{
	int		i;
	t_stack	*f_n;
	t_stack	*l_n;

	i = 0;
	f_n = *stack;
	l_n = *stack;
	if (!*stack)
		return (f_n);
	while (l_n->rear)
		l_n = l_n->rear;
	i = l_n->stack_index;
	while (f_n && l_n)
	{
		if (f_n->value_index == (i - num))
			return (f_n);
		if (l_n->value_index == (i - num))
			return (l_n);
		f_n = f_n->rear;
		l_n = l_n->top;
	}
	return (f_n);
}

void	find_and_send2(t_stack **stacka, t_stack **stackb, int range)
{
	int		i;

	i = 0;
	while (i < range)
	{
		send_chunk2(stacka, stackb, i, 50);
		i = i + 50;
	}
}

void	find_location2(t_stack **stacka, t_stack **stackb, int range)
{
	t_stack	*node_needed1;
	t_stack	*node_needed2;

	node_needed1 = *stackb;
	node_needed2 = *stackb;
	while (range > 0)
	{
		if (!*stackb)
			return ;
		node_needed1 = send_big_number2(stackb, 0);
		node_needed2 = send_big_number2(stackb, 1);
		if (find_nearest(node_needed1, node_needed2) == 1)
		{
			send_btoa(stacka, stackb, node_needed1);
			range--;
		}
		else
		{
			send_btoa(stacka, stackb, node_needed2);
			send_btoa(stacka, stackb, node_needed1);
			stack_sa(stacka, 0);
			range = range - 2;
		}
	}
}

void	sort_all(t_stack **stacka, t_stack **stackb, int size)
{
	find_and_send2(stacka, stackb, size);
	repair_stack(stackb);
	find_location2(stacka, stackb, size);
}
