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
/*   Updated: 2024/05/27 15:18:13 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Prints perror and exit with status 1 */
void	perror_and_exit(char *errormsg)
{
	perror(errormsg);
	exit(EXIT_FAILURE);
}

/* Prints custom error message for invalid identifier for export */
int	export_unset_error(char *arg, char *type)
{
	write(2, type, ft_strlen(type));
	write(2, ": `", 3);
	write(2, arg, ft_strlen(arg));
	write(2, "': not a valid identifier\n", 26);
	g_global.error_no = 1;
	return (1);
}