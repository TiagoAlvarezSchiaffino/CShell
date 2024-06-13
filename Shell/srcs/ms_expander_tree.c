/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expander_tree.c                                           	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:34:10 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 17:38:02 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ms_expander_delete_null(t_list **list)
{
	t_list	*curr;

	if (list == NULL || *list == NULL)
		return ;
	curr = *list;
	if (*(char **)curr->content == NULL)
	{
		*list = curr->next;
		free(curr->content);
		free(curr);
		curr = NULL;
		ms_expander_delete_null(list);
	}
	else if (**(char **)curr->content == 0)
	{
		*list = curr->next;
		free(*(char **)curr->content);
		free(curr->content);
		free(curr);
		curr = NULL;
		ms_expander_delete_null(list);
	}
	curr = *list;
	if (curr)
		ms_expander_delete_null(&curr->next);
}