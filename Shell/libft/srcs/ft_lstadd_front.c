/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_lstadd_front.c  	                                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 15:04:41 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 15:06:03 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}