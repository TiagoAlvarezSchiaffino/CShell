/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ms_cd.c                          		                                  */
/*                                                                            */
/*   By: Tiago <tiagoalvarezschiaffino@gmail.com>                             */
/*                                                             / \__          */
/*                                                            (    @\___      */
/*                                                             /         O    */
/*   Created: 2024/05/16 19:39:47 by Tiago                    /   (_____/     */
/*   Updated: 2024/06/14 07:45:11 by Tiago                  /_____/ U         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/**
 * @brief Checks whether there is a cd command. If no, return 0 . If yes, then
 * will change current directory and return 1. If changing directory fails, throw
 * error and exit with status 1
 * 
 * @param main Main struct containing the environment array
 * @param args Arguments that will be cd into
 * @return int 0 on success
 */
int	ms_cd(t_main *main, char **args)
{
	char	*path;

	if (args[1] == 0)
	{
		path = ms_get_envp_value(main->envp, "HOME");
		if (path == NULL)
			ft_dprintf(STDERR_FILENO, "HOME not set\n");
		else if (chdir(path) < 0)
			perror(path);
		free(path);
	}
	else if (chdir(args[1]) < 0)
		perror(args[1]);
	return (0);
}