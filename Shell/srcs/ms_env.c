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
/*   Updated: 2024/05/30 18:40:54 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Prints out everyline in environment list
 * 
 * @param main The main struct containing the environment list
 * @param args The arguments (Can be NULL)
 * @return int 0 on success
 */
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