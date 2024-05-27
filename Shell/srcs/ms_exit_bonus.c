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
/*   Updated: 2024/05/27 14:19:31 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ms_exit(t_main *main, char **args)
{
	write(1, "exit\n", 5);
	system("leaks -q minishell");
	exit(0);
	return (0);
	(void)main;
	(void)args;
}