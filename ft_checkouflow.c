/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkouflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:48:40 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/15 18:21:43 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_checkouflow(char *str)
{
	long long	handler;
	int			i;
	int			sign;

	i = 0;
	handler = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (((handler * 10 + (str[i] - 48)) * sign) > 2147483647)
			return ('b');
		if (((handler * 10 + (str[i] - 48)) * sign) < -2147483648)
			return ('b');
		handler = handler * 10 + (str[i] - 48);
		i++;
	}
	return ('g');
}
