/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:39:12 by rmatthes          #+#    #+#             */
/*   Updated: 2025/07/28 14:44:51 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*second_node;
	t_list	*last_node;

	ft_putendl_fd("rr", 1);
	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second_node = (*stack_a)->next;
	last_node = ft_lstlast(*stack_a);
	(*stack_a)->next = NULL;
	last_node->next = *stack_a;
	*stack_a = second_node;
	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	second_node = (*stack_b)->next;
	last_node = ft_lstlast(*stack_b);
	(*stack_b)->next = NULL;
	last_node->next = *stack_b;
	*stack_b = second_node;
}
