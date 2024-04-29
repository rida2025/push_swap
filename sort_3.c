/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:08:12 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/24 10:40:07 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stackA)
{
	t_stack	*f_n;
	t_stack	*m_n;
	t_stack	*l_n;

	f_n = *stackA;
	m_n = (*stackA)->rear;
	l_n = (*stackA)->rear->rear;
	if (m_n->value < f_n->value && f_n->value < l_n->value)
		stack_sa(stackA, 0);
	else if (f_n->value > m_n->value && m_n->value > l_n->value)
	{
		stack_sa(stackA, 0);
		stack_rra(stackA, 0);
	}
	else if (f_n->value > l_n->value && l_n->value > m_n->value)
		stack_ra(stackA, 0);
	else if (m_n->value > f_n->value && f_n->value > l_n->value)
		stack_rra(stackA, 0);
	else if (m_n->value > l_n->value && l_n->value > f_n->value)
	{
		stack_sa(stackA, 0);
		stack_ra(stackA, 0);
	}
}
