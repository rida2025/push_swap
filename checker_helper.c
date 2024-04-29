/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:38:27 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 14:10:18 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_operation(char *strs)
{
	if (ft_strcmp(strs, "sa") == 0 || ft_strcmp(strs, "sb") == 0 || \
	ft_strcmp(strs, "ss") == 0 || ft_strcmp(strs, "pa") == 0 || \
	ft_strcmp(strs, "pb") == 0 || ft_strcmp(strs, "ra") == 0 || \
	ft_strcmp(strs, "rb") == 0 || ft_strcmp(strs, "rr") == 0 || \
	ft_strcmp(strs, "rra") == 0 || ft_strcmp(strs, "rrb") == 0 || \
	ft_strcmp(strs, "rrr") == 0)
		return (1);
	return (0);
}
