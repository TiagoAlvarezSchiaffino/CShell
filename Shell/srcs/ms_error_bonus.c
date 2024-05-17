/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_error_bonus.c                                                         */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/16 21:34:02 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Prints perror and exit with status 1 */
void	perror_and_exit(char *errormsg)
{
	perror(errormsg);
	exit(1);
}