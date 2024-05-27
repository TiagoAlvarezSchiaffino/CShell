/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_exit_bonus.c                                                          */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 14:33:28 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Writes out exit message and exits minishell */
int	ms_exit(t_main *main, char **args)
{
	write(1, "exit\n", 5);
	system("leaks -q minishell");
	exit(EXIT_SUCCESS);
	return (0);
	(void)main;
	(void)args;
}