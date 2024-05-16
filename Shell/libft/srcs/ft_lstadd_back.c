/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lstadd_back.c  	                                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 15:02:32 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 15:04:17 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst)
		return ;
	if (*lst != NULL)
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
	else
		*lst = new;
}