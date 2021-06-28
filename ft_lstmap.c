/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:30:00 by lmarquar          #+#    #+#             */
/*   Updated: 2021/06/04 13:30:00 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*p;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	p = (t_list *)malloc(sizeof(t_list));
	res = p;
	while (lst)
	{
		p->next = (t_list *)malloc(sizeof(t_list));
		p->content = f(lst->content);
		temp = p;
		p = p->next;
		lst = lst->next;
	}
	del(p);
	free(p);
	temp->next = NULL;
	return (res);
}
