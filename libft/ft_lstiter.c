/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:52:48 by catarina          #+#    #+#             */
/*   Updated: 2025/01/02 11:22:04 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*#include "ft_lstnew.c"
#include <stdio.h>

static void print_node(void *content);

int	main(void)
{
	t_list	*node1 = ft_lstnew("Hello");
	t_list	*node2 = ft_lstnew("World!");
	t_list	*node3 = ft_lstnew("Bye");
	t_list	*node4 = ft_lstnew("World!");

	if (!node1 || !node2 || !node3 || !node4)
	{
		printf("Memory allocation fail!\n");
		free(node1);
		free(node2);
		free(node3);
		free(node4);
		return (1);
	}

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	ft_lstiter(node1, print_node);

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}

static void print_node(void *content)
{
    printf("%s\n", (char *)content);
}*/