/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_lexer_utils.c                                                 	      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/30 17:15:23 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 07:11:05 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief 	Checks if string has a special token at the start. Special tokens
 * are: && || << >> < > | ( )
 * 
 * @param s 	String to check
 * @return int 1 if there is a token at the start of the string, 0 if not.
 */
int	ms_lexer_is_spec(char *s)
{
	if (ft_strchr("|<>()", *s))
		return (1);
	if (ft_strncmp(s, "&&", 2) == 0)
		return (1);
	return (0);
}