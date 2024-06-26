/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_heredoc.c                                               	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:46:49 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 18:55:36 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Starts the heredoc and writes everything from standard input fd to the
 * newly created fd until the delimiter is written. Then adds a new node to the
 * back of the heredoc linked list containing the fd that were piped
 * 
 * @param heredoc Heredoc linked list for fd to be added back
 * @param delimiter Delimiter of the heredoc
 */
void	ms_heredoc_enqueue(t_list **heredoc, char *delimiter)
{
	char	*buffer;
	int		*fd;

	fd = ft_calloc(2, sizeof(int));
	pipe(fd);
	ft_printf("> ");
	buffer = get_next_line(STDIN_FILENO);
	while (buffer)
	{
		if (!ft_strncmp(delimiter, buffer, ft_strlen(buffer) - 1)
			&& (ft_strlen(delimiter) == ft_strlen(buffer) - 1))
		{
			free(buffer);
			break ;
		}
		ft_dprintf(fd[1], buffer, ft_strlen(buffer));
		free(buffer);
		ft_printf("> ");
		buffer = get_next_line(STDIN_FILENO);
	}
	close(fd[1]);
	ft_lstadd_back(heredoc, ft_lstnew(fd));
}

/**
 * @brief Dequeues and frees the current node of the heredoc linked list
 * 
 * @param heredoc Heredoc linked list containing the current node to be deleted
 * @return int fd of the heredoc
 */
int	ms_heredoc_dequeue(t_list **heredoc)
{
	int		res;
	t_list	*temp;

	temp = *heredoc;
	*heredoc = (*heredoc)->next;
	res = *(int *)temp->content;
	ft_lstdelone(temp, &free);
	return (res);
}