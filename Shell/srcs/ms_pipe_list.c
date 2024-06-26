/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_pipe_list.c                                                           */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 17:33:24 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 19:06:10 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Inits pipe list.
 * 
 * @return t_pipe* Returns a malloced pipe list node.
 */
t_pipe	*ms_pipe_list_init(void)
{
	t_pipe	*pipe_list;

	pipe_list = ft_calloc(1, sizeof(t_pipe));
	pipe_list->argv = NULL;
	pipe_list->io_list = NULL;
	pipe_list->next = NULL;
	return (pipe_list);
}

/**
 * @brief Appends node to pipe list and moves the buffer to new node. If both
 * argv and io list is empty (i.e. current pipe list is empty), prints error and
 * return.
 * 
 * @param p Parser struct.
 * @param buffer Pointer to pipe list buffer.
 */
static int	ms_parser_pipe_next(t_parser *p, t_pipe **buffer)
{
	if ((*buffer)->argv == NULL && (*buffer)->io_list == NULL)
	{
		ms_parser_syntax_error(p);
		return (1);
	}
	(*buffer)->next = ms_pipe_list_init();
	*buffer = (*buffer)->next;
	return (0);
}

/**
 * @brief Parses a pipe list.
 * 
 * @param p Parser struct.
 * @return t_pipe* Pointer to pipe list head.
 */
t_pipe	*ms_parser_parse_pipe_list(t_parser *p)
{
	t_pipe	*pipe_list;
	t_pipe	*buffer;

	pipe_list = ms_pipe_list_init();
	buffer = pipe_list;
	while (p->curr_token && p->syntax_error == 0)
	{
		if (p->curr_token->e_type == TOKEN_WORD)
			ms_pipe_new_arg(buffer, p);
		else if (p->curr_token->e_type == TOKEN_PIPE
			&& ms_parser_pipe_next(p, &buffer))
			return (pipe_list);
		else if (ms_parser_is_io_token(p->curr_token)
			&& ms_parser_parse_io_list(&buffer->io_list, p))
			return (pipe_list);
		else if (!ms_parser_is_pipe_token(p->curr_token))
			break ;
		ms_parser_eat(p);
	}
	if (buffer->argv == NULL && buffer->io_list == NULL)
		ms_parser_syntax_error(p);
	return (pipe_list);
}

/**
 * @brief Checks if token is one of word token, '|', '<<', '>>', '<', '>'
 * 
 * @param token Token to check
 * @return int 1 if token is pipe list token, 0 if not
 */
int	ms_parser_is_pipe_token(t_token *token)
{
	return (token->e_type == TOKEN_WORD
		|| token->e_type == TOKEN_PIPE
		|| ms_parser_is_io_token(token));
}

/**
 * @brief Frees pipe list and its contents.
 * 
 * @param pipe_list Pointer to pointer of pipe list struct.
 */
void	ms_pipe_list_free(t_pipe **pipe_list)
{
	t_pipe	*temp;

	while (*pipe_list)
	{
		temp = *pipe_list;
		*pipe_list = (*pipe_list)->next;
		ft_lstclear(&temp->argv, &ms_free_args);
		ms_io_list_free(&temp->io_list);
		free(temp);
	}
}