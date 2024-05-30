/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_token.c                                                               */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 17:52:40 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/30 17:55:28 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Inits token node.
 * 
 * @param type Token type.
 * @param value Token value.
 * @return t_token* Returns malloced token node.
 */
t_token	*ms_token_init(int type, char *value)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->e_type = type;
	token->value = value;
	return (token);
}

/**
 * @brief Frees token struct and sets pointer to NULL.
 * 
 * @param token Pointer to pointer to token struct.
 */
void	ms_token_free(t_token **token)
{
	free(*token);
	*token = NULL;
}