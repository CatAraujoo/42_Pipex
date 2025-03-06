/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:52:58 by catarina          #+#    #+#             */
/*   Updated: 2025/02/03 11:00:19 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = (t_list *)malloc (sizeof(t_list));
	if (!n)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}
/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		t_list	*node1 = ft_lstnew((char *)av[1]);
		t_list	*node2 = ft_lstnew((char *)av[2]);
		t_list	*node3 = ft_lstnew((char *)av[3]);

		printf("Node1->content: %s, located at: %p\n\n", 
		(char *)node1->content, (char *)node1->content);
		printf("Node2->content: %s, located at: %p\n\n",
		(char *)node2->content, (char *)node2->content);
		printf("Node3->content: %s, located at: %p\n",
		(char *)node3->content, (char *)node3->content);
		free(node1);
		free(node2);
		free(node3);
		return (0);
	}
	printf("Usage: 'av[1]' 'av[2]' 'av[3]'\n");
	return (1);
}*/