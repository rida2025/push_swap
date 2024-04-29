/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilitis2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:51:02 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/22 14:38:17 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_ra(t_stack **stacka, int signel)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (!*stacka || !(*stacka)->rear)
		return ;
	first_node = *stacka;
	second_node = (*stacka)->rear;
	last_node = *stacka;
	while (last_node->rear)
		last_node = last_node->rear;
	second_node->top = NULL;
	first_node->rear = NULL;
	first_node->top = last_node;
	last_node->rear = first_node;
	*stacka = second_node;
	if (signel != 2)
		write(1, "ra\n", 3);
	repair_stack(stacka);
}

void	stack_rb(t_stack **stackb, int signel)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (!*stackb || !(*stackb)->rear)
		return ;
	first_node = *stackb;
	second_node = (*stackb)->rear;
	last_node = *stackb;
	if (!first_node | !second_node)
		return ;
	while (last_node->rear)
		last_node = last_node->rear;
	second_node->top = NULL;
	first_node->rear = NULL;
	first_node->top = last_node;
	last_node->rear = first_node;
	*stackb = second_node;
	if (signel != 2)
		write(1, "rb\n", 3);
	repair_stack(stackb);
}

void	stack_rr(t_stack **stacka, t_stack **stackb, int signel)
{
	if (!*stacka || !*stackb)
		return ;
	stack_ra(stacka, 2);
	stack_rb(stackb, 2);
	if (signel != 2)
		write(1, "rr\n", 3);
}

void	stack_rra(t_stack **stacka, int signel)
{
	t_stack	*first_node;
	t_stack	*b_last_node;
	t_stack	*last_node;

	if (!*stacka || !(*stacka)->rear)
		return ;
	first_node = *stacka;
	last_node = *stacka;
	while (last_node->rear)
		last_node = last_node->rear;
	b_last_node = last_node->top;
	b_last_node->rear = NULL;
	last_node->top = NULL;
	last_node->rear = first_node;
	first_node->top = last_node;
	*stacka = last_node;
	if (signel != 2)
		write(1, "rra\n", 4);
	repair_stack(stacka);
}

void	stack_rrb(t_stack **stackb, int signel)
{
	t_stack	*first_node;
	t_stack	*b_last_node;
	t_stack	*last_node;

	if (!*stackb || !(*stackb)->rear)
		return ;
	first_node = *stackb;
	last_node = *stackb;
	while (last_node->rear)
		last_node = last_node->rear;
	b_last_node = last_node->top;
	if (!b_last_node)
		return ;
	b_last_node->rear = NULL;
	last_node->top = NULL;
	last_node->rear = first_node;
	first_node->top = last_node;
	*stackb = last_node;
	if (signel != 2)
		write(1, "rrb\n", 4);
	repair_stack(stackb);
}
