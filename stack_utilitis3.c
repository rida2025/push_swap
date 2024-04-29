/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilitis3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:57:46 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 09:43:19 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rrr(t_stack **stacka, t_stack **stackb, int signel)
{
	if (!*stacka || !*stackb)
		return ;
	stack_rra(stacka, 2);
	stack_rrb(stackb, 2);
	if (signel != 2)
		write(1, "rrr\n", 4);
}

void	helper_pa1(t_stack **stacka, t_stack **stackb)
{
	t_stack	*first_nodea;
	t_stack	*first_nodeb;

	first_nodea = *stacka;
	first_nodeb = *stackb;
	(*stackb) = first_nodeb->rear;
	(*stackb)->top = NULL;
	if (!*stacka)
	{
		*stacka = first_nodeb;
		(*stacka)->rear = NULL;
	}
	else
	{
		first_nodeb->rear = first_nodea;
		first_nodea->top = first_nodeb;
		(*stacka) = first_nodeb;
	}
}

void	helper_pa2(t_stack **stacka, t_stack **stackb)
{
	t_stack	*first_nodea;
	t_stack	*first_nodeb;

	first_nodea = *stacka;
	first_nodeb = *stackb;
	*stackb = NULL;
	if (!*stacka)
	{
		*stacka = first_nodeb;
		(*stacka)->rear = NULL;
	}
	else
	{
		first_nodeb->rear = first_nodea;
		first_nodea->top = first_nodeb;
		(*stacka) = first_nodeb;
	}
}

void	helper_pb1(t_stack **stacka, t_stack **stackb)
{
	t_stack	*first_nodea;
	t_stack	*first_nodeb;

	first_nodea = *stacka;
	first_nodeb = *stackb;
	(*stacka) = first_nodea->rear;
	(*stacka)->top = NULL;
	if (!*stackb)
	{
		*stackb = first_nodea;
		(*stackb)->rear = NULL;
	}
	else
	{
		first_nodea->rear = first_nodeb;
		first_nodeb->top = first_nodea;
		*stackb = first_nodea;
	}
}

void	helper_pb2(t_stack **stacka, t_stack **stackb)
{
	t_stack	*first_nodea;
	t_stack	*first_nodeb;

	first_nodea = *stacka;
	first_nodeb = *stackb;
	*stacka = NULL;
	if (!*stackb)
	{
		*stackb = first_nodea;
		(*stacka)->rear = NULL;
	}
	else
	{
		first_nodea->rear = first_nodeb;
		first_nodeb->top = first_nodea;
		*stackb = first_nodea;
	}
}
