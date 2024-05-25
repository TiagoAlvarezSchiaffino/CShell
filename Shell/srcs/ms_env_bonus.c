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
/*   Updated: 2024/05/25 08:14:02 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	env(char **args, t_main *main)
{
	int	i;

	ft_printf("Hello");
	return (0);
    i = -1;
	while (main->envp[++i] != NULL)
		ft_printf("%s\n", main->envp[i]);
	(void)args;
}