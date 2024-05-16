/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lstdelone.c      	                                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 15:07:30 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 15:08:02 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	(*del)(lst->content);
	temp = lst->next;
	free(lst);
	lst = temp;
}