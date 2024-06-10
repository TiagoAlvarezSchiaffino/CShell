/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*    temp_debugger.c                         		                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 18:18:46 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/10 16:37:11 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief To print the linked list
 * 
 * @param head The head of the linked list
 */
void	print_ll(t_list *head)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = head;
	ft_printf("\nPRINTING LL\n");
	while (temp != NULL)
	{
		ft_printf("%d: |%s|\n", i++, *(char **)temp->content);
		temp = temp->next;
	}
	ft_printf("PRINTING END\n");
}