/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_exit.c                               	                              */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/13 06:35:40 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Writes out exit message and exits with status 0
 * 
 * @param main Main struct (Can be NULL)
 * @param args Argument (Can be NULL)
 * @return int 0 on success
 */
int	ms_exit(t_main *main, char **args)
{
	ft_printf("exit\n");
	system("leaks -q shell");
	exit(EXIT_SUCCESS);
	return (0);
	(void)main;
	(void)args;
}