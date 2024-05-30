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
/*   Updated: 2024/05/30 16:46:19 by Tiago                  /_____/ U         */
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
	curr = *list;
	if (curr)
		ms_expander_delete_null(&curr->next);
}

void	ms_expander_io_list(t_main *main, t_io_list *io_list)
{
	while (io_list)
	{
		if (io_list->e_type != IO_AIN)
		{
			expander(main, &io_list->value);
			ms_expander_delete_null(&io_list->value);
		}
		io_list = io_list->next;
	}
}

void	ms_expander_pipe_list(t_main *main, t_pipe_list *pipe_list)
{
	while (pipe_list)
	{
		expander(main, &pipe_list->argv);
		ms_expander_delete_null(&pipe_list->argv);
		ms_expander_io_list(main, pipe_list->io_list);
		pipe_list = pipe_list->next;
	}
}

void	ms_expander_cmd_list(t_main *main, t_cmd_list *cmd_list)
{
	while (cmd_list)
	{
		if (cmd_list->e_type == CMD_LIST)
			ms_expander_cmd_list(main, cmd_list->ptr);
		else
			ms_expander_pipe_list(main, cmd_list->ptr);
		cmd_list = cmd_list->next;
	}
}