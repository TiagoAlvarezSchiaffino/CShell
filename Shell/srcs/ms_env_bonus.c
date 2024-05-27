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
/*   Updated: 2024/05/27 14:17:12 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	env(t_main *main, char **args)
{
	int	i;

    i = -1;
	while (main->envp[++i] != 0)
		ft_printf("%s\n", main->envp[i]);
	return (0);
	(void)args;
}