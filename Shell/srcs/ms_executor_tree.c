/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_executor_tree.c                                         	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:34:04 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 06:03:10 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ms_executor_wait_pipe(void)
{
	int	returnpid;
	int	status;

	returnpid = 1;
	while (returnpid > 0)
		returnpid = waitpid(-1, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_errno = (WEXITSTATUS(status));
}

void	ms_executor_pipe_list(t_main *main, t_executor *exec, t_pipe_list *pipe)
{
	exec->pipe_count = 0;
	ms_executor_init_pipefd(exec, pipe);
	while (pipe)
	{
		exec->infile = 0;
		exec->outfile = 1;
		ms_executor_io_list(main, exec, pipe->io_list);
		if (exec->runtime_error)
			g_errno = exec->runtime_error;
		else
			ms_executor(main, exec, pipe);
		pipe = pipe->next;
		exec->pipe_count++;
	}
	ms_executor_free_pipefd(exec);
	ms_executor_wait_pipe();
}

void	ms_executor_cmd_list(t_main *main, t_executor *e, t_cmd_list *cmd)
{
	while (cmd)
	{
		if (cmd->e_operator == OP_START
			|| (cmd->e_operator == OP_AND && g_errno == 0)
			|| (cmd->e_operator == OP_OR && g_errno != 0))
		{
			if (cmd->e_type == PIPE_LIST)
				ms_executor_pipe_list(main, e, cmd->ptr);
			else
				ms_executor_cmd_list(main, e, cmd->ptr);
		}
		else
		{
			if (cmd->e_type == PIPE_LIST)
				ms_heredoc_pipe_list_dequeue(e, cmd->ptr);
			else
				ms_heredoc_cmd_list_dequeue(e, cmd->ptr);
		}
		cmd = cmd->next;
	}
}