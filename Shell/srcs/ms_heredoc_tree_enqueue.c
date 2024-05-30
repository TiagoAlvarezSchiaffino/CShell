/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_heredoc_tree_enqueue.c                                    	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:43:16 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 16:48:58 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ms_heredoc_io_list_enqueue(t_executor *exec, t_io_list *io_list)
{
	while (io_list)
	{
		if (io_list->e_type == IO_AIN)
			ms_heredoc_enqueue(&exec->heredoc,
				*(char **)io_list->value->content);
		io_list = io_list->next;
	}
}

void	ms_heredoc_pipe_list_enqueue(t_executor *exec, t_pipe_list *pipe_list)
{
	while (pipe_list)
	{
		ms_heredoc_io_list_enqueue(exec, pipe_list->io_list);
		pipe_list = pipe_list->next;
	}
}

void	ms_heredoc_cmd_list_enqueue(t_executor *exec, t_cmd_list *cmd_list)
{
	while (cmd_list)
	{
		if (cmd_list->e_type == PIPE_LIST)
			ms_heredoc_pipe_list_enqueue(exec, cmd_list->ptr);
		else
			ms_heredoc_pipe_list_enqueue(exec, cmd_list->ptr);
		cmd_list = cmd_list->next;
	}
}