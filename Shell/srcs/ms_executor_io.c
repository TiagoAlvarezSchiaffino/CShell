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
/*   Updated: 2024/06/13 05:34:36 by Tiago                  /_____/ U         */
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

static int	ms_executor_check_ambiguous(t_executor *exec, t_list *value,
	char *env_val)
{
	if (ft_lstsize(value) != 1)
	{
		ft_dprintf(2, "minishell: %s: ambiguous redirect\n", env_val);
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
		exec->infile = open(*(char **)io->value->content, O_RDONLY);
}

static void	ms_executor_io_out(t_executor *exec, t_io_list *io)
{
	if (exec->outfile != 1)
		close(exec->outfile);
	if (io->e_type == IO_AOUT)
		exec->outfile = open(*(char **)io->value->content,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		exec->outfile = open(*(char **)io->value->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	ms_executor_io_list(t_main *main, t_executor *exec, t_io_list *io)
{
	char	*env_val;

	while (io)
	{
		if (io->e_type != IO_AIN)
		{
			env_val = ft_strdup(*(char **)io->value->content);
			expander(main, &io->value);
			ms_expander_delete_null(&io->value);
			if (ms_executor_check_ambiguous(exec, io->value, env_val))
			{
				free(env_val);
				return ;
			}
			free(env_val);
		}
		if (io->e_type == IO_AIN || io->e_type == IO_IN)
			ms_executor_io_in(exec, io);
		else if (io->e_type == IO_AOUT || io->e_type == IO_OUT)
			ms_executor_io_out(exec, io);
		if (ms_executor_check_file_error(exec, *(char **)io->value->content))
			return ;
		io = io->next;
	}
}