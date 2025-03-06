/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:02:51 by catarina          #+#    #+#             */
/*   Updated: 2025/02/03 10:55:59 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include "ft_strdup.c"
#include "ft_strlen.c"*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
static void	del(void *lst)
{
	free(lst);
}
int	main(void)
{
	t_list *list = NULL;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = ft_strdup("hello!");
	node1->next = node2;

	node2->content = ft_strdup("world!");
	node2->next = node3;

	node3->content = ft_strdup("!");
	node3->next = NULL;

	list = node1;

	ft_lstclear(&list, del);

	if (list == NULL)
		printf("List successfully cleared.\n");
	else
	{
		printf("List not cleared. Freeing remaining nodes...\n");
		while (list)
		{
			t_list *temp = list;
			list = list->next;
			del(temp->content);
			free(temp);
		}
		printf("Remaining nodes freed.\n");
	}
	return (0);
}*/