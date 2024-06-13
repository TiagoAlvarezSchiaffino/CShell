/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_error.c                                                               */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 06:22:33 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Prints perror and exit with status 1
 * 
 * @param errormsg Error message to be printed
 */
void	perror_and_exit(char *errormsg)
{
	perror(errormsg);
	exit(EXIT_FAILURE);
}

/**
 * @brief Prints error message for invalid identifier for export or unset and
 * updates the errno to 1
 * 
 * @param arg Argument that is invalid
 * @param type The type of builtin function it is called from (unset or export)
 * @return int 1 to be set as errno
 */
int	export_unset_error(char *arg, char *type)
{
	ft_dprintf(STDERR_FILENO, "%s: `%s': not a valid identifier\n", type, arg);
	return (1);
}

/**
 * @brief Prints syntax error using the current token in the parser and sets the
 * member syntax_error in the parser struct to 1.
 * 
 * @param p Parser struct containing current token value and syntax error boolean
 */
void	ms_parser_syntax_error(t_parser *p)
{
	ft_dprintf(2, "shell: syntax error near unexpected token `%s'\n",
		p->curr_token->value);
	p->syntax_error = 1;
}