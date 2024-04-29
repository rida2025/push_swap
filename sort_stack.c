/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:29:41 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/20 19:17:07 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack **stackA, t_stack **stackB)
{
	int	size;

	size = stack_size(stackA);
	if (size == 2)
		sort_2(stackA);
	else if (size == 3)
		sort_3(stackA);
	else if (size <= 5)
		sort_5(stackA, stackB, size);
	else if (size <= 100)
		sort_100(stackA, stackB, size);
	else
		sort_all(stackA, stackB, size);
}
