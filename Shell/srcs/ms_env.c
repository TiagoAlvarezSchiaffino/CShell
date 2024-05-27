/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_env.c                      		                                      */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/05/27 15:53:29 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/* Prints out everyline in environment list */
int	env(t_main *main, char **args)
{
	int		i;
	char	**split;

    i = -1;
	while (main->envp[++i] != 0)
	{
		split = envp_split(main->envp[i]);
		if (split[1] != 0)
			ft_printf("%s\n", main->envp[i]);
		free_doublearray(split);
	}
	return (0);
	(void)args;
}