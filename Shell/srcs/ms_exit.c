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
/*   Updated: 2024/05/30 14:32:48 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Writes out exit message and exits with status 0
 * 
 * @param main The main struct (Can be NULL)
 * @param args The arguments (Can be NULL)
 * @return int 0 on success
 */
int	ms_exit(t_main *main, char **args)
{
	ft_printf("exit\n");
	system("leaks -q minishell");
	exit(EXIT_SUCCESS);
	return (0);
	(void)main;
	(void)args;
}