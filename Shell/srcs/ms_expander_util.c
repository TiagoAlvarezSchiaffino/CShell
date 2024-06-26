/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_expander_util.c                                           	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:34:10 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 07:23:46 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Deletes the node of the argument list if the content is NULL
 * 
 * @param list List of arguments to delete null from
 */
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
	curr = *list;
	if (curr)
		ms_expander_delete_null(&curr->next);
}

/**
 * @brief Checks if the string has spaces only
 * 
 * @param str The string to check
 * @return int 1 if the string only has spaces, else 0
 */
int	ms_is_space_only(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (str[i] == '\0');
}