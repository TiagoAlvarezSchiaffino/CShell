/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_io_list.c                                               	          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 16:49:30 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 18:09:34 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Inits io list with type.
 * 
 * @param type Type to set in io list struct.
 * @return t_io_list* Returns a malloced io list node.
 */
t_io_list	*ms_io_list_init(int type)
{
	t_io_list	*io_list;

	io_list = ft_calloc(1, sizeof(t_io_list));
	io_list->e_type = type;
	io_list->value = NULL;
	io_list->next = NULL;
	return (io_list);
}

/**
 * @brief Parses an io list node and appends it to the io list.
 * 
 * @param io_list Io list.
 * @param p Parser struct.
 */
int	ms_parser_parse_io_list(t_io_list **io_list, t_parser *p)
{
	t_io_list	*new;
	t_io_list	*buffer;
	int			type;

	type = p->curr_token->e_type - 3;
	ms_parser_eat(p);
	if (p->curr_token->e_type != TOKEN_WORD)
	{
		ms_parser_syntax_error(p);
		return (1);
	}
	new = ms_io_list_init(type);
	new->value = ft_lstnew(ft_calloc(1, sizeof(char *)));
	ft_memcpy(new->value->content, &p->curr_token->value, sizeof(char *));
	if (*io_list != NULL)
	{
		buffer = *io_list;
		while (buffer->next != NULL)
			buffer = buffer->next;
		buffer->next = new;
	}
	else
		*io_list = new;
	return (0);
}

/** 
 * @brief Checks if token is one of '<<', '>>', '<', '>'
 * 
 * @param token Token to check
 * @return int 1 if token is io token, 0 if not
 */
int	ms_parser_is_io_token(t_token *token)
{
	return (token->e_type == TOKEN_AIN
		|| token->e_type == TOKEN_AOUT
		|| token->e_type == TOKEN_IN
		|| token->e_type == TOKEN_OUT);
}

/**
 * @brief Frees io list and its contents.
 * 
 * @param io_list Pointer to pointer of io list struct.
 */
void	ms_io_list_free(t_io_list **io_list)
{
	t_io_list	*temp;

	while (*io_list)
	{
		temp = *io_list;
		*io_list = (*io_list)->next;
		ft_lstclear(&temp->value, &ms_free_args);
		free(temp);
	}
}