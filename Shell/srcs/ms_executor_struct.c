/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_executor_struct.c                                         	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:32:13 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 16:33:55 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_executor	*ms_executor_init(void)
{
	t_executor	*exec;

	exec = ft_calloc(1, sizeof(t_executor));
	exec->heredoc = NULL;
	exec->pipe_fd = ft_calloc(2, sizeof(int *));
	exec->pipe_fd[0] = ft_calloc(2, sizeof(int));
	exec->pipe_fd[1] = ft_calloc(2, sizeof(int));
	exec->infile = 0;
	exec->outfile = 1;
	exec->runtime_error = 0;
	pipe(exec->pipe_fd[0]);
	pipe(exec->pipe_fd[1]);
	return (exec);
}