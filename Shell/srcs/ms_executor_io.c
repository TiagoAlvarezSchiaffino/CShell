/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_executor_io.c                                         	              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/06/10 16:51:20 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/10 17:03:17 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ms_executor_check_file_error(t_executor *exec, char *filename)
{
	if (exec->infile == -1 || exec->outfile == -1)
	{
		ft_dprintf(2, "minishell: %s: %s\n", filename, strerror(errno));
		exec->runtime_error = 1;
	}
	return (exec->runtime_error);
}

static int	ms_executor_check_ambiguous(t_executor *exec, t_list *value)
{
	if (ft_lstsize(value) != 1)
	{
		ft_dprintf(2, "minishell: ambiguous redirect\n");
		exec->runtime_error = 1;
		return (1);
	}
	return (0);
}

static void	ms_executor_io_in(t_executor *exec, t_io_list *io)
{
	if (exec->infile != 0)
		close(exec->infile);
	if (io->e_type == IO_AIN)
		exec->infile = ms_heredoc_dequeue(&exec->heredoc);
	else
	{
		if (ms_executor_check_ambiguous(exec, io->value))
			return ;
		exec->infile = open(*(char **)io->value->content, O_RDONLY);
	}
}

static void	ms_executor_io_out(t_executor *exec, t_io_list *io)
{
	if (exec->outfile != 1)
		close(exec->outfile);
	if (ms_executor_check_ambiguous(exec, io->value))
		return ;
	if (io->e_type == IO_AOUT)
		exec->outfile = open(*(char **)io->value->content,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		exec->outfile = open(*(char **)io->value->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	ms_executor_io_list(t_main *main, t_executor *exec, t_io_list *io)
{
	while (io)
	{
		if (io->e_type != IO_AIN)
		{
			expander(main, &io->value);
			ms_expander_delete_null(&io->value);
		}
		if (io->e_type == IO_AIN || io->e_type == IO_IN)
			ms_executor_io_in(exec, io);
		else if (io->e_type == IO_AOUT || io->e_type == IO_OUT)
			ms_executor_io_out(exec, io);
		if (ms_executor_check_error(exec, exec->infile == -1)
			|| ms_executor_check_error(exec, exec->outfile == -1))
			return ;
		io = io->next;
	}
}