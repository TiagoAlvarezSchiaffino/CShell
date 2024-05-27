/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_env_bonus.c                                                           */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 14:32:04 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Prints out everyline in environment list */
int	env(t_main *main, char **args)
{
	int	i;

    i = -1;
	while (main->envp[++i] != 0)
		ft_printf("%s\n", main->envp[i]);
	return (0);
	(void)args;
}