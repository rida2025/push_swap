/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilitis1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:17:22 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/23 14:21:01 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sa(t_stack **stacka, int signel)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!(*stacka))
		return ;
	first_node = *stacka;
	second_node = (*stacka)->rear;
	second_node->top = NULL;
	if ((*stacka)->rear->rear)
		second_node->rear->top = first_node;
	first_node->rear = second_node->rear;
	first_node->top = second_node;
	second_node->rear = first_node;
	*stacka = second_node;
	if (signel != 2)
		write(1, "sa\n", 3);
	repair_stack(stacka);
}

void	stack_sb(t_stack **stackb, int signel)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!*stackb)
		return ;
	first_node = *stackb;
	second_node = (*stackb)->rear;
	second_node->top = NULL;
	second_node->rear->top = first_node;
	first_node->rear = second_node->rear;
	first_node->top = second_node;
	second_node->rear = first_node;
	*stackb = second_node;
	if (signel != 2)
		write(1, "sb\n", 3);
	repair_stack(stackb);
}

void	stack_ss(t_stack **stacka, t_stack **stackb, int signel)
{
	if (!*stackb || !*stackb)
		return ;
	stack_sa(stacka, 2);
	stack_sb(stackb, 2);
	if (signel != 2)
		write(1, "ss\n", 3);
}

void	stack_pa(t_stack **stacka, t_stack **stackb, int signel)
{
	t_stack	*first_nodea;
	t_stack	*first_nodeb;

	first_nodea = *stacka;
	first_nodeb = *stackb;
	if (!*stackb)
		return ;
	if ((*stackb)->rear)
		helper_pa1(stacka, stackb);
	else
		helper_pa2(stacka, stackb);
	if (signel != 2)
		write(1, "pa\n", 3);
	repair_stack(stacka);
	repair_stack(stackb);
}

void	stack_pb(t_stack **stacka, t_stack **stackb, int signel)
{
	t_stack	*first_nodea;
	t_stack	*first_nodeb;

	first_nodea = *stacka;
	first_nodeb = *stackb;
	if (!*stacka)
		return ;
	if ((*stacka)->rear)
		helper_pb1(stacka, stackb);
	else
		helper_pb2(stacka, stackb);
	if (signel != 2)
		write(1, "pb\n", 3);
	repair_stack(stacka);
	repair_stack(stackb);
}
